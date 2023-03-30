global main

extern printf

section .text

main:
	mov	edi, msg
	xor	eax, eax
	call	printf
	mov	eax, 0
	ret	

section .rodata
msg: db "Hello, Holberton", 10, 0
