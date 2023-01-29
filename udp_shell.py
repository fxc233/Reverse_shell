# nc -u 127.0.0.1 1337
import sys
import socket

IP = "127.0.0.1"
PORT = 1337

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
	command = input("shell # ")
	if not command:
		continue
	if "exit" in command:
		s.close()
		break
	command += "\n"
	s.sendto(command.encode(), (IP, PORT))
	data, addr = s.recvfrom(4096)
	print(data.decode())

