#!/bin/bash

apt update -y && apt upgrade -y
apt install sudo -y

echo "####config sudo####"
cat <<EOF > /etc/sudoers.d/no-passare
Defaults log_input,log_output
Defaults iolog_dir=/var/log/sudo/
Defaults logfile=/var/log/sudo.log, log_year
# Le mode TTY sera activé pour des questions de sécurité.
Defaults requiretty
# secu timeout
Defaults passwd_timeout=0
# print message on wrong passwd
Defaults  badpass_message="Mot de passe incorrect, merci de réessayer. 
Si vous avez oublié le mot de passe, contactez votre administrateur."
# limit nb try for pass
Defaults   passwd_tries=3
%sudo ALL=(ALL) /usr/local/sbin,/usr/local/bin,/usr/sbin,/usr/bin,/sbin,/bin,/snap/bin
EOF

echo "###config passwd###"
apt install libpam-pwquality libpwquality-tools -y
# Définir les valeurs souhaitées
PASS_MAX_DAYS=30
PASS_MIN_DAYS=2
PASS_WARN_AGE=7
ENCRYPT_METHOD=SHA512

# Modifier /etc/login.defs en place
sed -i \
    -e "s/^\s*PASS_MAX_DAYS\s\+.*/PASS_MAX_DAYS\t$PASS_MAX_DAYS/" \
    -e "s/^\s*PASS_MIN_DAYS\s\+.*/PASS_MIN_DAYS\t$PASS_MIN_DAYS/" \
    -e "s/^\s*PASS_WARN_AGE\s\+.*/PASS_WARN_AGE\t$PASS_WARN_AGE/" \
    -e "s/^\s*ENCRYPT_METHOD\s\+.*/ENCRYPT_METHOD\t$ENCRYPT_METHOD/" \
    /etc/login.defs

cat <<EOF > /etc/security/pwquality.conf
retry=3
minlen=10
dcredit=-1
ucredit=-1
lcredit=-1
maxrepeat=3
usercheck=1
EOF

cat <<EOF > /etc/pam.d/common-password
password [success=1 default=ignore] pam_succeed_if.so uid = 0

# Règle difok uniquement pour les users non-root
password requisite pam_pwquality.so difok=7

# Règles globales (minlen, crédits, etc.)
password requisite pam_pwquality.so enforce_for_root

password requisite pam_unix.so obscure use_authtok try_first_pass sha512
EOF

#add user
getent group user42 >/dev/null || addgroup user42
id lamjadab >/dev/null 2>&1 || adduser lamjadab user42

## ssh config 

echo "###SSH###"
apt install openssh-client -y
apt install openssh-server -y

echo "Port 4242" > /etc/ssh/sshd_config.d/1000-port.conf
printf "MaxAuthTries 3\nPermitRootLogin no" > /etc/ssh/sshd_config.d/2000-policy.conf
systemctl restart ssh

### ufw config 
apt install ufw -y
ufw --force enable
ufw allow ssh
ufw allow 4242/tcp
ufw deny 22/tcp

### monitoring 
apt install bc sysstat net-tools

cp ./monitoring.sh /usr/local/bin/monitoring.sh

chmod 644 /etc/cron.d/monitoring
