	.text
	.file	"\344\270\255\346\226\255.c"
	.globl	_hint00                 # -- Begin function _hint00
	.p2align	4, 0x90
	.type	_hint00,@function
_hint00:                                # @_hint00
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	leal	.L.str, %eax
	movl	%eax, (%esp)
	calll	"_Z6输出Pc"
	movl	$160, %eax
	movl	$32, %ecx
	movl	$160, (%esp)
	movl	$32, 4(%esp)
	movl	%eax, -4(%ebp)          # 4-byte Spill
	movl	%ecx, -8(%ebp)          # 4-byte Spill
	calll	"io_写入8位"
	movl	$32, %eax
	movl	$32, (%esp)
	movl	$32, 4(%esp)
	movl	%eax, -12(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	addl	$24, %esp
	popl	%ebp
	retl
.Lfunc_end0:
	.size	_hint00, .Lfunc_end0-_hint00
                                        # -- End function
	.globl	"idt_初始化"         # -- Begin function idt_初始化
	.p2align	4, 0x90
	.type	"idt_初始化",@function
"idt_初始化":                        # @"idt_\E5\88\9D\E5\A7\8B\E5\8C\96"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	subl	$52, %esp
	calll	"pic_初始化"
	calll	*"内存"
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	shrl	$12, %eax
	shll	$2, %eax
	addl	$16789504, %eax         # imm = 0x1003000
	movl	-8(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	$0, 8(%esp)
	movl	$1, 12(%esp)
	movl	%edx, -16(%ebp)         # 4-byte Spill
	movl	%ecx, -20(%ebp)         # 4-byte Spill
	calll	"页_建立_临时"
	movl	$4096, %eax             # imm = 0x1000
	movl	-8(%ebp), %ecx
	addl	$-1073741824, %ecx      # imm = 0xC0000000
	movl	%ecx, "idt_地址"
	movl	"idt_地址", %ecx
	movl	%ecx, (%esp)
	movl	$4096, 4(%esp)          # imm = 0x1000
	movl	%eax, -24(%ebp)         # 4-byte Spill
	calll	"mem_清零"
	movl	$0, -12(%ebp)
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$255, -12(%ebp)
	jge	.LBB1_4
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	leal	_hint00, %eax
	movl	$8, %ecx
	movl	"idt_地址", %edx
	movl	-12(%ebp), %esi
	shll	$3, %esi
	addl	%esi, %edx
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	movl	$8, 8(%esp)
	movl	%ecx, -28(%ebp)         # 4-byte Spill
	calll	"idt_创建"
# %bb.3:                                #   in Loop: Header=BB1_1 Depth=1
	movl	-12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -12(%ebp)
	jmp	.LBB1_1
.LBB1_4:
	movl	$4096, %eax             # imm = 0x1000
	movl	-8(%ebp), %ecx
	movl	$4096, (%esp)           # imm = 0x1000
	movl	%ecx, 4(%esp)
	movl	%eax, -32(%ebp)         # 4-byte Spill
	calll	"IDTR_设置"
	calll	"io_开启中断"
	addl	$52, %esp
	popl	%esi
	popl	%ebp
	retl
.Lfunc_end1:
	.size	"idt_初始化", .Lfunc_end1-"idt_初始化"
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function idt_创建
	.type	"idt_创建",@function
"idt_创建":                           # @"idt_\E5\88\9B\E5\BB\BA"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$12, %esp
	movl	16(%ebp), %eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	movl	8(%ebp), %esi
	movl	4(%esi), %edi
	andl	$-256, %edi
	movl	%edi, 4(%esi)
	movl	8(%ebp), %esi
	movl	4(%esi), %edi
	andl	$-3841, %edi            # imm = 0xF0FF
	orl	$3584, %edi             # imm = 0xE00
	movl	%edi, 4(%esi)
	movl	8(%ebp), %esi
	movl	4(%esi), %edi
	andl	$-24577, %edi           # imm = 0x9FFF
	movl	%edi, 4(%esi)
	movl	16(%ebp), %esi
	movl	8(%ebp), %edi
	movw	%si, %bx
	movw	%bx, 2(%edi)
	movw	12(%ebp), %bx
	movl	8(%ebp), %esi
	movw	%bx, (%esi)
	movw	14(%ebp), %bx
	movl	8(%ebp), %esi
	movw	%bx, 6(%esi)
	movl	8(%ebp), %esi
	movl	4(%esi), %edi
	andl	$-4097, %edi            # imm = 0xEFFF
	movl	%edi, 4(%esi)
	movl	8(%ebp), %esi
	movl	4(%esi), %edi
	orl	$32768, %edi            # imm = 0x8000
	movl	%edi, 4(%esi)
	movl	%eax, -16(%ebp)         # 4-byte Spill
	movl	%ecx, -20(%ebp)         # 4-byte Spill
	movl	%edx, -24(%ebp)         # 4-byte Spill
	addl	$12, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.Lfunc_end2:
	.size	"idt_创建", .Lfunc_end2-"idt_创建"
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function pic_初始化
	.type	"pic_初始化",@function
"pic_初始化":                        # @"pic_\E5\88\9D\E5\A7\8B\E5\8C\96"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$104, %esp
	movl	$33, %eax
	movl	$255, %ecx
	movl	$33, (%esp)
	movl	$255, 4(%esp)
	movl	%eax, -4(%ebp)          # 4-byte Spill
	movl	%ecx, -8(%ebp)          # 4-byte Spill
	calll	"io_写入8位"
	movl	$161, %eax
	movl	$255, %ecx
	movl	$161, (%esp)
	movl	$255, 4(%esp)
	movl	%eax, -12(%ebp)         # 4-byte Spill
	movl	%ecx, -16(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$32, %eax
	movl	$17, %ecx
	movl	$32, (%esp)
	movl	$17, 4(%esp)
	movl	%eax, -20(%ebp)         # 4-byte Spill
	movl	%ecx, -24(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$33, %eax
	movl	$32, %ecx
	movl	$33, (%esp)
	movl	$32, 4(%esp)
	movl	%eax, -28(%ebp)         # 4-byte Spill
	movl	%ecx, -32(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$33, %eax
	movl	$4, %ecx
	movl	$33, (%esp)
	movl	$4, 4(%esp)
	movl	%eax, -36(%ebp)         # 4-byte Spill
	movl	%ecx, -40(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$33, %eax
	movl	$1, %ecx
	movl	$33, (%esp)
	movl	$1, 4(%esp)
	movl	%eax, -44(%ebp)         # 4-byte Spill
	movl	%ecx, -48(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$160, %eax
	movl	$17, %ecx
	movl	$160, (%esp)
	movl	$17, 4(%esp)
	movl	%eax, -52(%ebp)         # 4-byte Spill
	movl	%ecx, -56(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$161, %eax
	movl	$40, %ecx
	movl	$161, (%esp)
	movl	$40, 4(%esp)
	movl	%eax, -60(%ebp)         # 4-byte Spill
	movl	%ecx, -64(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$161, %eax
	movl	$2, %ecx
	movl	$161, (%esp)
	movl	$2, 4(%esp)
	movl	%eax, -68(%ebp)         # 4-byte Spill
	movl	%ecx, -72(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$161, %eax
	movl	$1, %ecx
	movl	$161, (%esp)
	movl	$1, 4(%esp)
	movl	%eax, -76(%ebp)         # 4-byte Spill
	movl	%ecx, -80(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$33, %eax
	movl	$253, %ecx
	movl	$33, (%esp)
	movl	$253, 4(%esp)
	movl	%eax, -84(%ebp)         # 4-byte Spill
	movl	%ecx, -88(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	movl	$161, %eax
	movl	$255, %ecx
	movl	$161, (%esp)
	movl	$255, 4(%esp)
	movl	%eax, -92(%ebp)         # 4-byte Spill
	movl	%ecx, -96(%ebp)         # 4-byte Spill
	calll	"io_写入8位"
	addl	$104, %esp
	popl	%ebp
	retl
.Lfunc_end3:
	.size	"pic_初始化", .Lfunc_end3-"pic_初始化"
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"lll666"
	.size	.L.str, 7

	.type	"内存",@object        # @"\E5\86\85\E5\AD\98"
	.comm	"内存",28,4
	.type	"idt_地址",@object    # @"idt_\E5\9C\B0\E5\9D\80"
	.local	"idt_地址"
	.comm	"idt_地址",4,4
	.type	"屏幕",@object        # @"\E5\B1\8F\E5\B9\95"
	.comm	"屏幕",20,4

	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
