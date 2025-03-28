def sniff(self):
    hosts_up = set([f'{str(self.host)} *'])
    try:
        while True:
            # Read a packet
            raw_buffer = self.socket.recvfrom(65535)[0]
            # Create an IP header from the first 20 bytes
            ip_header = IP(raw_buffer[0:20])
            # If it's ICMP, we want it
            if ip_header.protocol == "ICMP":
                offset = ip_header.ihl * 4
                buf = raw_buffer[offset:offset + 8]
                icmp_header = ICMP(buf)
                # Check for TYPE 3 and CODE
                if icmp_header.code == 3 and icmp_header.type == 3:
                    if ipaddress.ip_address(ip_header.src_address) in ipaddress.IPv4Network(SUBNET):
                        # Make sure it has our magic message
                        if raw_buffer[len(raw_buffer) - len(MESSAGE):] == bytes(MESSAGE, 'utf8'):
                            tgt = str(ip_header.src_address)
                            if tgt != self.host and tgt not in hosts_up:
                                hosts_up.add(str(ip_header.src_address))
                                print(f'Host Up: {tgt}')
    except KeyboardInterrupt:
        if os.name == 'nt':
            self.socket.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)
        print('\nUser interrupted.')
        if hosts_up:
            print(f'\nSummary: Hosts up on {SUBNET}')
            for host in sorted(hosts_up):
                print(f'{host}')
            print('')
        sys.exit()

if __name__ == '__main__':
    if len(sys.argv) == 2:
        host = sys.argv[1]
    else:
        host = '192.168.1.203'
    s = Scanner(host)
    time.sleep(5)
    t = threading.Thread(target=udp_sender)
    t.start()
    s.sniff()