sudo dnsmasq --interface=natbr0 --bind-interfaces --dhcp-range=192.168.100.50,192.168.100.150,12h --dhcp-host=00:11:22:66:88:22,192.168.100.100 
