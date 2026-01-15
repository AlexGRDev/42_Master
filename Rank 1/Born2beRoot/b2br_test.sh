
#!/bin/bash

yesno () {
    if [ "$1" -eq 0 ]; then
        echo "YES"
    else
        echo "NO"
    fi
}

os (){
	if [ "$1" -eq 0 ]; then
		echo "Debian"
	else
		echo "Rocky"
	fi
}
echo "==============================="
echo " Born2beroot – TEST"
echo "==============================="
echo

### OS ###
echo -n "OS is Debian or Rocky: "
grep -qiE "debian|rocky" /etc/os-release ; os $?

### NO GUI ###
echo -n "Graphical environment: "
! systemctl get-default | grep -qi graphical ; yesno $?

### PASSWORD POLICY ###
echo -n "Password policy set: "
grep -q "PASS_MAX_DAYS" /etc/login.defs ; yesno $?

### USER ###
echo -n "User in sudo group: "
id "$USER" | grep -q sudo ; yesno $?

echo -n "User in user42 group: "
id "$USER" | grep -q user42 ; yesno $?

### HOSTNAME ###
echo -n "Hostname format login42: "
hostname | grep -q "42" ; yesno $?

### SUDO ###
echo -n "sudo installed: "
command -v sudo &>/dev/null ; yesno $?

echo -n "sudo logs enabled: "
[ -d /var/log/sudo ] ; yesno $?

### FIREWALL ###
echo -n "UFW active: "
sudo ufw status | grep -qi "active" ; yesno $? 

### SSH ###
echo -n "SSH installed: "
systemctl  status ssh | grep -qi "enabled" ; yesno $?

echo -n "SSH uses port 4242: "
ss -tuln | grep -q 4242 ; yesno $?

echo -n "Root login enabled  in SSH: "
grep -qi "PermitRootLogin no" /etc/ssh/sshd_config ; yesno $?

### CRON ###
echo -n "Cron job exists: "
sudo journalctl -u cron | grep "uid=0" | grep -E ':(00|10|20|30|40|50):' &>/dev/null ; yesno $?

### MONITORING SCRIPT ###
echo -n "Monitoring script present: "
find / -name "*monitor*.sh" 2>/dev/null | grep -q . ; yesno $?

### LVM ###
echo -n "LVM in use: "
lsblk | grep -q lvm ; yesno $?

echo
echo "==============================="
echo " END TEST"
echo "==============================="


