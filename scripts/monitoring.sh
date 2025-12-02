#!/bin/bash

ARCHI=$(uname -a)
KERNEL=$(uname -r)

CPU_P=$(lscpu | grep "Socket(s)" | awk '{print $2}')
CPU_V=$(nproc)

RAM_TOTAL=$(free -m | awk '/Mem/ {print $2}')
RAM_USAGE=$(free -m | awk '/Mem/ {print $3}')
RAM_U=$(echo "$RAM_USAGE * 100 / $RAM_TOTAL" | bc)

DISK_SIZE=$(df -h --total | awk '/total/ {print $2}')
DISK_USAGE=$(df -h --total | awk '/total/ {print $5}')

CPU_L=$(iostat -c | awk '/avg-cpu/ {getline; print 100 - $6}')

LB=$(last boot | grep "begin" | awk '{print $3, $5, $4, $7, $6}')

LVM="no"
if grep -q "/dev/mapper/" /etc/fstab; then
    LVM="yes"
fi

CON=$(netstat -nat | awk 'NR>2 {print $6}' | sort | uniq -c)

NB_USER=$(who | awk '{print $1}' | uniq | wc -l)

IP=$(hostname -I)
MAC=$(ifconfig | grep "..:..:..:..:..:.." | awk '{print $2}')

NB_SUDO_CMD=$(journalctl _COMM=sudo | wc -l)

wall "
Architecture: $ARCHI
Kernel: $KERNEL
CPU: $CPU_P sockets, $CPU_V cores
RAM total: ${RAM_TOTAL}MB
RAM utilisée: ${RAM_USAGE}MB (${RAM_U}%)
Disque total: $DISK_SIZE
Usage du disque: $DISK_USAGE
Charge CPU: ${CPU_L}%
Dernier boot: $LB
LVM: $LVM
Connexions:
$CON

Utilisateurs connectés: $NB_USER
Adresse IP: $IP
Adresse MAC: $MAC
Commandes sudo: $NB_SUDO_CMD
"
