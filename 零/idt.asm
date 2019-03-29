
extern _zongtizhongduan
GLOBAL _hint00 , _hint01,_hint0x

; _hint00 为起始点 _hint01 -_hint00 为每一块大小,剩下的地址就能推出来




%MACRO int1__  1 

   
    push %1    
    call _zongtizhongduan 
%ENDM

    ;//没有错误值
%MACRO intzzz 1 
    int1__ %1         
    jmp near  _end 
%ENDMACRO


    ;//有错误值    
%MACRO intzzz1 1  
    int1__ %1    
    jmp near  _end1 
%ENDMACRO




[section .text]
[bits 32]

_end1:
   ; add esp ,4
_end:
    add esp ,4
    push eax
    mov al,0x20
    out 0xa0,al
    out  0x20 ,al
    pop eax
    sti
    iret
 
 
align 16	
_hint00:
    intzzz 0
 _hint01:
intzzz 1
intzzz 2
intzzz 3
intzzz 4
intzzz 5
intzzz 6
intzzz 7
intzzz 8
intzzz 9
intzzz 10
intzzz 11
intzzz 12
intzzz 13
intzzz 14
intzzz 15
intzzz 16
intzzz 17
intzzz 18
intzzz 19
intzzz 20
intzzz 21
intzzz 22
intzzz 23
intzzz 24
intzzz 25
intzzz 26
intzzz 27
intzzz 28
intzzz 29

intzzz 30
intzzz 31
intzzz 32
intzzz 33
intzzz 34
intzzz 35
intzzz 36
intzzz 37
intzzz 38
intzzz 39
;有错误值的
intzzz1 40
intzzz1 41
intzzz1 42
intzzz1 43
intzzz1 44
intzzz1 45
intzzz1 46
intzzz1 47
intzzz1 48
intzzz1 49
intzzz1 50
intzzz1 51
intzzz1 52
intzzz1 53
intzzz1 54
intzzz1 55
intzzz1 56
intzzz1 57
intzzz1 58
intzzz1 59
intzzz1 60
 
_hint0x:

