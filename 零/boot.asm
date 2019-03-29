
bits 16
org 0x7c00

%define	BASE	0x100
%define KSIZE	50


jmp start


start:
	mov ax,0
	mov ds,ax
	mov es,ax
	mov [bootdrv],dl
	mov ax,0xb800	
	mov es,ax	
	mov byte [es:0],'a'
	
	mov ax,0x8000
	mov ss,ax
	mov sp,0xf000
	
	mov di,0
	mov si,0
	
	
	
	push es
	mov ax,BASE
	mov es,ax
	mov bx,0
	mov ah,2
	mov al,KSIZE
	mov ch,0
	mov cl,2
	mov dh,0
	mov dl,[bootdrv]
	;mov dl,0
	;mov dl,80
	int 0x13
	pop es
	add ah,'a'
	mov byte [es:4],ah  ;ah是错误码，如果错了一定显示比‘a’大

	jmp readok

readok:	
	;mov ax,0xb800	
	;mov es,ax
	;mov byte [es:0],'b'
	;jmp end
	
	cli 
	in al,0x92
	or al,010B
	out 0x92,al
	
	lgdt [gdt_48]
	
	mov eax,cr0
	or eax,1
	mov cr0,eax

	jmp next
next:
	mov ax,0x10
	mov ds,ax 
	mov fs,ax 
	mov gs,ax 
	mov es,ax
	mov ss,ax
	mov esp,0x9f000

	jmp dword 0x8:0x1000

	jmp end
	
	
	
	
end:
	jmp $	
	
	
align 4	

	
bootdrv: db 0,0,0,0
	
gdt:
	dd 0,0
	dd 0x0000ffff,0x00cf9a00
	dd 0x0000ffff,0x00cf9200
	dd 0x0000ffff,0x80c7fa00
	dd 0x0000ffff,0x80c7f200

gdt_48:
	dw 40
	dd gdt,0
	
times 510-($-$$) db 144
dw 0xAA55	

