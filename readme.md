# Simple hello-goodbye linux kernel module 

## Requirements 
Linux kernel version 5.14

## Usage
-cd to `~/develop/kernel` <br>
- clone the repo <br>
- run `sudo insmod hello.ko` for enable kernel module and check system logs `dmesg` u see 'Hello world' <br>
- run `sudo rmmod hello` for disable kernel module and check system logs `dmesg` u see 'Goodbye world' <br>

## Implementation logs
- Install kernel headers for Ubuntu:
```
sudo apt-get update
```
```
apt-cache search linux-headers-`uname -r` 
```
<br>

- Create directory
`mkdir -p ~/develop/kernel/hello ` 
`cd ~/develop/kernel/hello`
<br>
- Create hello.c <br>
- Create Makefile to build hello.c and run `make`  <br>

## Team 
``` ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄    ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄   ▄▄ 
█       █  ▄    █       █  █       █       █      █  █▄█  █ 
█   ▄   █ █▄█   █    ▄  █  █▄     ▄█    ▄▄▄█  ▄   █       █ 
█  █▄█  █       █   █▄█ █    █   █ █   █▄▄▄█ █▄█  █       █ 
█       █  ▄   ██    ▄▄▄█    █   █ █    ▄▄▄█      █       █ 
█   ▄   █ █▄█   █   █        █   █ █   █▄▄▄█  ▄   █ ██▄██ █ 
█▄▄█ █▄▄█▄▄▄▄▄▄▄█▄▄▄█        █▄▄▄█ █▄▄▄▄▄▄▄█▄█ █▄▄█▄█   █▄█ 
```
