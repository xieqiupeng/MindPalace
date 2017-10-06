;A include file used with io.lib
	.nolist

;declare procedures for inputting and outputting binary number
	extrn readbb:near,readbw:near,readbd:near
	extrn dispbb:near,dispbw:near,dispbd:near
;declare procedures for inputting and outputting hexadecimal number
	extrn readhb:near,readhw:near,readhd:near
	extrn disphb:near,disphw:near,disphd:near
;declare procedures for inputting and outputting unsigned integer number
	extrn readuib:near,readuiw:near,readuid:near
	extrn dispuib:near,dispuiw:near,dispuid:near
;declare procedures for inputting and outputting signed integer number
	extrn readsib:near,readsiw:near,readsid:near
	extrn dispsib:near,dispsiw:near,dispsid:near
;declare procedures for outputting registers
	extrn disprb:near,disprw:near,disprd:near,disprf:near

;define macro
dispmsg	macro msg
	push ax
	push dx
	mov dx,offset msg
	mov ah,9
	int 21h
	pop dx
	pop ax
	endm

;declare I/O libraries
	includelib io.lib

	.list