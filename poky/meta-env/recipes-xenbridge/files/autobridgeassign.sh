#!/bin/bash
set -e

sudo ip link add name natbr0 type bridge 
sudo ip addr add 192.168.100.1/24 dev natbr0
sudo ip link set natbr0 up

sudo iptables -t nat -C POSTROUTING -s 192.168.100.0/24 -o wlan0 -j MASQUERADE 
sudo dnsmasq --interface=natbr0 --bind-interfaces --dhcp-range=192.168.100.50,192.168.100.150,12h --dhcp-host=00:11:22:66:88:22,192.168.100.100 
sudo dnsmasq --interface=natbr0 --bind-interfaces --dhcp-range=192.168.100.50,192.168.100.150,12h --dhcp-host=00:11:22:66:88:33,192.168.100.101