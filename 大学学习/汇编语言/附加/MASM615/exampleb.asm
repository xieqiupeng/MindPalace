;exampleb.asm
	.model small
	.486
	.stack
	.data

	.code
start:	mov ax,@data
	mov ds,ax
	;

	;
	mov ah,4ch
	int 21h
	;
	end start
