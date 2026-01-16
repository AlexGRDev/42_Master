# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    b2br_test.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 18:59:18 by agarcia2          #+#    #+#              #
#    Updated: 2026/01/16 07:46:52 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#=== SUDO CHECK ===#
if [ "$EUID" -ne 0 ]; then
    printf "%b" "${RESET} [✘] Necesitas ejecutarlo con sudo o como root.${RESET}"
    exit 1
fi

GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
CYAN="\033[1;36m"
RESET="\033[0m"

yesno () {
	if [ "$1" -eq 0 ]; then
		printf "%b" "${GREEN}[✔]${RESET}"
	else
		printf "%b" "${RED}[✘]${RESET}" 
	fi
}

os () {
	if [ "$1" -eq 0 ]; then
		printf "%b" "${GREEN}Debian${RESET}"
	else
		printf "%b" "${BLUE}Rocky${RESET}"
	fi
}

printf "%b" "${CYAN}"
printf "%s\n" "╔══════════════════════════════════════╗"
printf "%s\n" "║        🔥 Born2beroot TEST 🔥        ║"
printf "%s\n" "╚══════════════════════════════════════╝"
printf "%b" "${RESET}"

printf "%b\n" "${CYAN}› OS is Debian or Rocky: ${RESET}"
grep -qiE "debian|rocky" /etc/os-release ; os $?

printf "%b\n" "${CYAN}› Graphical environment: ${RESET}"
! systemctl get-default | grep -qi graphical ; yesno $?

printf "%b\n" "${CYAN}› Password policy set: ${RESET}"
grep -q "PASS_MAX_DAYS" /etc/login.defs ; yesno $?

printf "%b\n" "${CYAN}› User in sudo group: ${RESET}"
id "$SUDO_USER" | grep -q sudo ; yesno $?

printf "%b\n" "${CYAN}› User in user42 group: ${RESET}"
id "$SUDO_USER" | grep -q user42 ; yesno $?

printf "%b\n" "${CYAN}› Hostname format login42: ${RESET}"
hostname | grep -q "42" ; yesno $?

printf "%b\n" "${CYAN}› sudo installed: ${RESET}"
command -v sudo &>/dev/null ; yesno $?

printf "%b\n" "${CYAN}› sudo logs enabled: ${RESET}"
[ -d /var/log/sudo ] ; yesno $?

printf "%b\n" "${CYAN}› UFW active: ${RESET}"
ufw status | grep -qi "active" ; yesno $? 

printf "%b\n" "${CYAN}› SSH installed: ${RESET}"
systemctl status ssh | grep -qi "enabled" ; yesno $?

printf "%b\n" "${CYAN}› SSH uses port 4242: ${RESET}"
ss -tuln | grep -q 4242 ; yesno $?

printf "%b\n" "${CYAN}› Root login disabled: ${RESET}"
grep -qi "PermitRootLogin no" /etc/ssh/sshd_config ; yesno $?

printf "%b\n" "${CYAN}› Cron job exists: ${RESET}"
journalctl -u cron | grep "uid=0" | grep -E ':(00|10|20|30|40|50):' &>/dev/null ; yesno $?

printf "%b\n" "${CYAN}› Monitoring script present: ${RESET}"
find / -name "*monitor*.sh" 2>/dev/null | grep -q . ; yesno $?

printf "%b\n" "${CYAN}› LVM in use: ${RESET}"
lsblk | grep -q lvm ; yesno $?

printf "%b\n" "${CYAN}╔══════════════════════════╗"
printf "%s\n"   "║        END TEST          ║"
printf "%b\n"   "╚══════════════════════════╝${RESET}"