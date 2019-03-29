extern _zongtizhongduan
GLOBAL _hint00 , _hint01,__wgy_linshi,__wgy__shu
[section .data]
align 16	
dd 0,0
__wgy__shu: dd 0,0
__wgy_linshi: dd 0,0

[section .text]
[bits 32]



%MACRO intzzz 1 

    push %1
     call _zongtizhongduan   
    jmp _end 
%ENDMACRO



_end :
 
   
   add esp ,4
    push eax
    mov al,0x20
    out 0xa0,al
    out  0x20 ,al
    pop eax
    sti
    iret


%MACRO intzzz_ 1 

    push %1 

    jmp _end1 
%ENDMACRO


_end1 :
    call _zongtizhongduan
    add esp ,4
    ;add esp ,4
    push eax
    mov al,0x20
    out 0xa0,al
    out  0x20 ,al
    pop eax

    sti
    iret



