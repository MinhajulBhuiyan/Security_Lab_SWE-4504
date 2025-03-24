import socket
import os

# Host to listen on
HOST = '192.168.1.203'

def main():
    # Create raw socket, bind to public interface
    if os.name == 'nt':  # Check if the OS is Windows
        socket_protocol = socket.IPPROTO_IP  # Use IP protocol for raw sockets on Windows
    else:
        socket_protocol = socket.IPPROTO_ICMP  # Use ICMP protocol for raw sockets on Linux/macOS

    # Create a raw socket
    sniffer = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket_protocol)
    sniffer.bind((HOST, 0))  # Bind the socket to the specified host and any available port

    # Include the IP header in the capture
    sniffer.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)

    # If on Windows, enable promiscuous mode
    if os.name == 'nt':
        sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_ON)

    # Read one packet
    print(sniffer.recvfrom(65565))  # Receive a packet (max size 65565 bytes)

    # If on Windows, turn off promiscuous mode
    if os.name == 'nt':
        sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)

if __name__ == '__main__':
    main()