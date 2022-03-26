#!/bin/sh
# Issues https://1024.day

if [[ $EUID -ne 0 ]]; then
    clear
    echo "Error: This script must be run as root!"
    exit 1
fi

timedatectl set-timezone Asia/Shanghai

cat >/root/.bashrc<<EOF
export LS_OPTIONS='--color=auto'
eval "`dircolors`"
alias ls='ls $LS_OPTIONS -F'
alias ll='ls $LS_OPTIONS -lAF'
alias l='ls $LS_OPTIONS -lF'
#
# Some more alias to avoid making mistakes:
# alias rm='rm -i'
# alias cp='cp -i'
# alias mv='mv -i'
alias mkdir='mkdir -p'
alias h='history'
EOF

apt install vim -y

echo "set mouse-=a" > /root/.vimrc

cat >/etc/vim/vimrc<<EOF
set mouse-=a

set number

set autoindent

set background=dark

set showmatch

set hlsearch

set incsearch

set ignorecase

set showcmd

set smartcase

set compatible

let g:skip_defaults_vim = 1

runtime! debian.vim

if has("syntax")
  syntax on
endif

if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif
EOF

cat >/etc/security/limits.conf<<EOF
* soft     nproc          65535
* hard     nproc          65535
* soft     nofile         65535
* hard     nofile         65535

root soft     nproc          65535
root hard     nproc          65535
root soft     nofile         65535
root hard     nofile         65535

bro soft     nproc          65535
bro hard     nproc          65535
bro soft     nofile         65535
bro hard     nofile         65535
EOF

echo "session required pam_limits.so" >> /etc/pam.d/common-session

echo "session required pam_limits.so" >> /etc/pam.d/common-session-noninteractive

echo "DefaultLimitNOFILE=65535" >> /etc/systemd/system.conf

cat >/etc/sysctl.conf<<EOF
fs.file-max = 65535
net.ipv4.tcp_slow_start_after_idle = 0
net.ipv4.tcp_mtu_probing = 1
vm.swappiness = 10
net.core.default_qdisc = fq
net.ipv4.tcp_congestion_control = bbr
EOF

sleep 3 && reboot >/dev/null 2>&1