# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    b2br_test.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 18:59:18 by agarcia2          #+#    #+#              #
#    Updated: 2026/01/15 19:11:06 by agarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#=== SUDO CHECK ===#
if [ "$EUID" -ne 0 ]; then
    echo -e "\033[1;31m[✘] Necesitas ejecutarlo con sudo o como root.\033[0m"
    exit 1
fi

GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
CYAN="\033[1;36m"
RESET="\033[0m"

yesno () {
    if [ "$1" -eq 0 ]; then
        echo -e "${GREEN}[✔]${RESET}"
    else
        echo -e "${RED}[✘]${RESET}"
    fi
}

os () {
    if [ "$1" -eq 0 ]; then
        echo -e "${GREEN}Debian${RESET}"
    else
        echo -e "${BLUE}Rocky${RESET}"
    fi
}

echo -e "${CYAN}"
echo "╔══════════════════════════════════════╗"
echo "║        🔥 Born2beroot TEST 🔥        ║"
echo "╚══════════════════════════════════════╝"
echo -e "${RESET}"

echo -ne "${CYAN}› OS is Debian or Rocky: ${RESET}"
grep -qiE "debian|rocky" /etc/os-release ; os $?

echo -ne "${CYAN}› Graphical environment: ${RESET}"
! systemctl get-default | grep -qi graphical ; yesno $?

echo -ne "${CYAN}› Password policy set: ${RESET}"
grep -q "PASS_MAX_DAYS" /etc/login.defs ; yesno $?

echo -ne "${CYAN}› User in sudo group: ${RESET}"
id "$SUDO_USER" | grep -q sudo ; yesno $?

echo -ne "${CYAN}› User in user42 group: ${RESET}"
id "$SUDO_USER" | grep -q user42 ; yesno $?

echo -ne "${CYAN}› Hostname format login42: ${RESET}"
hostname | grep -q "42" ; yesno $?

echo -ne "${CYAN}› sudo installed: ${RESET}"
command -v sudo &>/dev/null ; yesno $?

echo -ne "${CYAN}› sudo logs enabled: ${RESET}"
[ -d /var/log/sudo ] ; yesno $?

echo -ne "${CYAN}› UFW active: ${RESET}"
ufw status | grep -qi "active" ; yesno $? 

echo -ne "${CYAN}› SSH installed: ${RESET}"
systemctl status ssh | grep -qi "enabled" ; yesno $?

echo -ne "${CYAN}› SSH uses port 4242: ${RESET}"
ss -tuln | grep -q 4242 ; yesno $?

echo -ne "${CYAN}› Root login disabled: ${RESET}"
grep -qi "PermitRootLogin no" /etc/ssh/sshd_config ; yesno $?

echo -ne "${CYAN}› Cron job exists: ${RESET}"
journalctl -u cron | grep "uid=0" | grep -E ':(00|10|20|30|40|50):' &>/dev/null ; yesno $?

echo -ne "${CYAN}› Monitoring script present: ${RESET}"
find / -name "*monitor*.sh" 2>/dev/null | grep -q . ; yesno $?

echo -ne "${CYAN}› LVM in use: ${RESET}"
lsblk | grep -q lvm ; yesno $?

echo -e "\n${CYAN}╔══════════════════════════╗"
echo -e   "║        END TEST          ║"
echo -e   "╚══════════════════════════╝${RESET}"