OBJ=boot.img
CC=clang  -w -m32
xunikongjian=0xC0001000
all:$(OBJ) 

bootsect: boot.asm
	nasm -f bin -o $@ $^ ;
kernel:main.o  第一屏d.o 物理内存.o str.o j基础类型.o io_gdt.o idt.o
	ld --oformat  binary  -e _start -Ttext $(xunikongjian) $^ -o $@
floppy:bootsect kernel
	cat bootsect kernel > floppy
two: main.o  str.o j基础类型.o 第一屏d.o 内核.o 物理内存.o  中断.o io_gdt.o idt.o
	ld --oformat binary -melf_i386 -e _start -Ttext $(xunikongjian) $^ -o $@
.o:.c
	$(CC) -c $^
idt.o: idt.asm
	nasm  -f elf   -o $@ $^ ;	
clean:
	rm -f $(OBJ) *.o	*.img floppy kernel bootsect two
	
boot.img:bootsect two
	dd if=bootsect of=$@ count=1 bs=512 seek=0
	dd if=two of=$@  bs=512 seek=1
boot.iso:bootsect kernel
	mkisofs  -o $@  -b $^ 	
#sudo apt install qemu-system-x86
run:boot.img
	qemu-system-i386 -m 64 -fda boot.img -boot a
rund:boot.img
	echo gdb target remote localhost:1234
	qemu-system-i386 -m 64 -S -s -fda boot.img -boot a 
	