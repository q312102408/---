	.text
	.file	"main.c"
	.globl	_start                  # -- Begin function _start
	.p2align	4, 0x90
	.type	_start,@function
_start:                                 # @_start
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	calll	"启动"
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	$98, %eax
	movl	$98, (%esp)
	movl	%eax, -4(%ebp)          # 4-byte Spill
	calll	"输出1"
	jmp	.LBB0_1
.Lfunc_end0:
	.size	_start, .Lfunc_end0-_start
                                        # -- End function
	.globl	"输出1"               # -- Begin function 输出1
	.p2align	4, 0x90
	.type	"输出1",@function
"输出1":                              # @"\E8\BE\93\E5\87\BA1"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	$753664, %ecx           # imm = 0xB8000
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %ecx
	movb	%cl, %dl
	movl	-4(%ebp), %ecx
	movb	%dl, (%ecx)
	movl	-4(%ebp), %ecx
	movb	$97, (%ecx)
	movl	8(%ebp), %ecx
	movb	%cl, %dl
	movl	-4(%ebp), %ecx
	movb	%dl, (%ecx)
	movl	%eax, -8(%ebp)          # 4-byte Spill
	addl	$8, %esp
	popl	%ebp
	retl
.Lfunc_end1:
	.size	"输出1", .Lfunc_end1-"输出1"
                                        # -- End function
	.globl	"计算物理大小"    # -- Begin function 计算物理大小
	.p2align	4, 0x90
	.type	"计算物理大小",@function
"计算物理大小":                   # @"\E8\AE\A1\E7\AE\97\E7\89\A9\E7\90\86\E5\A4\A7\E5\B0\8F"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$16781323, -8(%ebp)     # imm = 0x100100B
	movl	-8(%ebp), %eax
	movl	-8(%ebp), %ecx
	andl	$4095, %ecx             # imm = 0xFFF
	subl	%ecx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -4(%ebp)
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	movl	-4(%ebp), %eax
	cmpl	$2147483647, %eax       # imm = 0x7FFFFFFF
	jae	.LBB2_6
# %bb.2:                                #   in Loop: Header=BB2_1 Depth=1
	movl	-4(%ebp), %eax
	movb	(%eax), %cl
	movb	%cl, -13(%ebp)
	movzbl	-13(%ebp), %eax
	addl	$1, %eax
	movb	%al, %cl
	movl	-4(%ebp), %eax
	movb	%cl, (%eax)
	movl	-4(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	-13(%ebp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jne	.LBB2_4
# %bb.3:                                #   in Loop: Header=BB2_1 Depth=1
	movb	-13(%ebp), %al
	movl	-4(%ebp), %ecx
	movb	%al, (%ecx)
	movl	-4(%ebp), %ecx
	addl	$47185920, %ecx         # imm = 0x2D00000
	movl	%ecx, -4(%ebp)
	jmp	.LBB2_5
.LBB2_4:
	movl	-4(%ebp), %eax
	addl	$-47185920, %eax        # imm = 0xFD300000
	movl	%eax, -4(%ebp)
	jmp	.LBB2_6
.LBB2_5:                                #   in Loop: Header=BB2_1 Depth=1
	jmp	.LBB2_1
.LBB2_6:
	jmp	.LBB2_7
.LBB2_7:                                # =>This Inner Loop Header: Depth=1
	movl	-4(%ebp), %eax
	cmpl	$2147483647, %eax       # imm = 0x7FFFFFFF
	jae	.LBB2_12
# %bb.8:                                #   in Loop: Header=BB2_7 Depth=1
	movl	-4(%ebp), %eax
	movb	(%eax), %cl
	movb	%cl, -13(%ebp)
	movzbl	-13(%ebp), %eax
	addl	$1, %eax
	movb	%al, %cl
	movl	-4(%ebp), %eax
	movb	%cl, (%eax)
	movl	-4(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	-13(%ebp), %edx
	addl	$1, %edx
	cmpl	%edx, %eax
	jne	.LBB2_10
# %bb.9:                                #   in Loop: Header=BB2_7 Depth=1
	movb	-13(%ebp), %al
	movl	-4(%ebp), %ecx
	movb	%al, (%ecx)
	movl	-4(%ebp), %ecx
	addl	$1048576, %ecx          # imm = 0x100000
	movl	%ecx, -4(%ebp)
	jmp	.LBB2_11
.LBB2_10:
	movl	-4(%ebp), %eax
	addl	$-1048576, %eax         # imm = 0xFFF00000
	movl	%eax, -4(%ebp)
	jmp	.LBB2_12
.LBB2_11:                               #   in Loop: Header=BB2_7 Depth=1
	jmp	.LBB2_7
.LBB2_12:
	movl	-4(%ebp), %eax
	addl	$16, %esp
	popl	%ebp
	retl
.Lfunc_end2:
	.size	"计算物理大小", .Lfunc_end2-"计算物理大小"
                                        # -- End function
	.globl	"页_建立"            # -- Begin function 页_建立
	.p2align	4, 0x90
	.type	"页_建立",@function
"页_建立":                           # @"\E9\A1\B5_\E5\BB\BA\E7\AB\8B"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	subl	$20, %esp
	movl	20(%ebp), %eax
	movl	16(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	8(%ebp), %esi
	movl	8(%ebp), %edi
	movl	%edi, -12(%ebp)
	cmpl	$0, 12(%ebp)
	movl	%eax, -16(%ebp)         # 4-byte Spill
	movl	%ecx, -20(%ebp)         # 4-byte Spill
	movl	%edx, -24(%ebp)         # 4-byte Spill
	movl	%esi, -28(%ebp)         # 4-byte Spill
	jne	.LBB3_2
# %bb.1:
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	jmp	.LBB3_9
.LBB3_2:
	movl	12(%ebp), %eax
	andl	$-4096, %eax            # imm = 0xF000
	movl	-12(%ebp), %ecx
	movl	%eax, (%ecx)
	cmpl	$0, 12(%ebp)
	je	.LBB3_4
# %bb.3:
	movl	-12(%ebp), %eax
	movl	(%eax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%eax)
.LBB3_4:
	cmpl	$0, 16(%ebp)
	je	.LBB3_6
# %bb.5:
	movl	-12(%ebp), %eax
	movl	(%eax), %ecx
	addl	$4, %ecx
	movl	%ecx, (%eax)
.LBB3_6:
	cmpl	$0, 20(%ebp)
	je	.LBB3_8
# %bb.7:
	movl	-12(%ebp), %eax
	movl	(%eax), %ecx
	addl	$2, %ecx
	movl	%ecx, (%eax)
.LBB3_8:
	jmp	.LBB3_9
.LBB3_9:
	addl	$20, %esp
	popl	%esi
	popl	%edi
	popl	%ebp
	retl
.Lfunc_end3:
	.size	"页_建立", .Lfunc_end3-"页_建立"
                                        # -- End function
	.globl	"页初始化"          # -- Begin function 页初始化
	.p2align	4, 0x90
	.type	"页初始化",@function
"页初始化":                         # @"\E9\A1\B5\E5\88\9D\E5\A7\8B\E5\8C\96"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	subl	$64, %esp
	movl	$16789504, %eax         # imm = 0x1003000
	movl	$16777216, %ecx         # imm = 0x1000000
	movl	%ecx, -12(%ebp)
	movl	%eax, -16(%ebp)
	movl	$0, -20(%ebp)
.LBB4_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$5, -20(%ebp)
	jge	.LBB4_4
# %bb.2:                                #   in Loop: Header=BB4_1 Depth=1
	xorl	%eax, %eax
	movl	$1, %ecx
	movl	-12(%ebp), %edx
	addl	$768, %edx              # imm = 0x300
	movl	-20(%ebp), %esi
	shll	$2, %esi
	addl	%esi, %edx
	movl	-16(%ebp), %esi
	movl	-20(%ebp), %edi
	shll	$10, %edi
	addl	%edi, %esi
	movl	%edx, (%esp)
	movl	%esi, 4(%esp)
	movl	$0, 8(%esp)
	movl	$1, 12(%esp)
	movl	%eax, -36(%ebp)         # 4-byte Spill
	movl	%ecx, -40(%ebp)         # 4-byte Spill
	calll	"页_建立"
# %bb.3:                                #   in Loop: Header=BB4_1 Depth=1
	movl	-20(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -20(%ebp)
	jmp	.LBB4_1
.LBB4_4:
	movl	$0, -24(%ebp)
.LBB4_5:                                # =>This Inner Loop Header: Depth=1
	cmpl	$5120, -24(%ebp)        # imm = 0x1400
	jge	.LBB4_8
# %bb.6:                                #   in Loop: Header=BB4_5 Depth=1
	xorl	%eax, %eax
	movl	$1, %ecx
	movl	-16(%ebp), %edx
	movl	-24(%ebp), %esi
	shll	$2, %esi
	addl	%esi, %edx
	movl	-24(%ebp), %esi
	shll	$12, %esi
	addl	$3221225472, %esi       # imm = 0xC0000000
	movl	%edx, (%esp)
	movl	%esi, 4(%esp)
	movl	$0, 8(%esp)
	movl	$1, 12(%esp)
	movl	%eax, -44(%ebp)         # 4-byte Spill
	movl	%ecx, -48(%ebp)         # 4-byte Spill
	calll	"页_建立"
# %bb.7:                                #   in Loop: Header=BB4_5 Depth=1
	movl	-24(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -24(%ebp)
	jmp	.LBB4_5
.LBB4_8:
	movl	$16777216, %eax         # imm = 0x1000000
	movl	%eax, -28(%ebp)
	calll	"计算物理大小"
	movl	-28(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	$0, -32(%ebp)
.LBB4_9:                                # =>This Inner Loop Header: Depth=1
	cmpl	$5, -32(%ebp)
	jge	.LBB4_12
# %bb.10:                               #   in Loop: Header=BB4_9 Depth=1
	xorl	%eax, %eax
	movl	$1, %ecx
	movl	-12(%ebp), %edx
	movl	-32(%ebp), %esi
	shll	$2, %esi
	addl	%esi, %edx
	movl	-16(%ebp), %esi
	movl	-32(%ebp), %edi
	shll	$10, %edi
	addl	%edi, %esi
	movl	%edx, (%esp)
	movl	%esi, 4(%esp)
	movl	$0, 8(%esp)
	movl	$1, 12(%esp)
	movl	%eax, -52(%ebp)         # 4-byte Spill
	movl	%ecx, -56(%ebp)         # 4-byte Spill
	calll	"页_建立"
# %bb.11:                               #   in Loop: Header=BB4_9 Depth=1
	movl	-32(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -32(%ebp)
	jmp	.LBB4_9
.LBB4_12:
	addl	$64, %esp
	popl	%esi
	popl	%edi
	popl	%ebp
	retl
.Lfunc_end4:
	.size	"页初始化", .Lfunc_end4-"页初始化"
                                        # -- End function
	.globl	"描述符_创建m"     # -- Begin function 描述符_创建m
	.p2align	4, 0x90
	.type	"描述符_创建m",@function
"描述符_创建m":                    # @"\E6\8F\8F\E8\BF\B0\E7\AC\A6_\E5\88\9B\E5\BB\BAm"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$64, %esp
	movl	40(%ebp), %eax
	movl	36(%ebp), %ecx
	movl	32(%ebp), %edx
	movl	28(%ebp), %esi
	movl	24(%ebp), %edi
	movl	20(%ebp), %ebx
	movl	%eax, -20(%ebp)         # 4-byte Spill
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)         # 4-byte Spill
	movl	12(%ebp), %eax
	movl	%eax, -28(%ebp)         # 4-byte Spill
	movl	8(%ebp), %eax
	movl	%eax, -32(%ebp)         # 4-byte Spill
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -36(%ebp)         # 4-byte Spill
	movl	24(%ebp), %eax
	movl	%eax, -40(%ebp)         # 4-byte Spill
	movl	-36(%ebp), %eax         # 4-byte Reload
	movl	4(%eax), %eax
	movl	%eax, -44(%ebp)         # 4-byte Spill
	movl	-40(%ebp), %eax         # 4-byte Reload
	andl	$3, %eax
	shll	$13, %eax
	movl	%eax, -48(%ebp)         # 4-byte Spill
	movl	-44(%ebp), %eax         # 4-byte Reload
	andl	$-24577, %eax           # imm = 0x9FFF
	movl	%ecx, -52(%ebp)         # 4-byte Spill
	movl	-48(%ebp), %ecx         # 4-byte Reload
	orl	%ecx, %eax
	movl	-36(%ebp), %ecx         # 4-byte Reload
	movl	%eax, 4(%ecx)
	movl	-16(%ebp), %eax
	movl	32(%ebp), %ecx
	movl	%eax, -56(%ebp)         # 4-byte Spill
	movl	4(%eax), %eax
	andl	$1, %ecx
	shll	$22, %ecx
	andl	$-4194305, %eax         # imm = 0xFFBFFFFF
	orl	%ecx, %eax
	movl	-56(%ebp), %ecx         # 4-byte Reload
	movl	%eax, 4(%ecx)
	movl	-16(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%eax, -60(%ebp)         # 4-byte Spill
	movl	4(%eax), %eax
	andl	$1, %ecx
	shll	$23, %ecx
	andl	$-8388609, %eax         # imm = 0xFF7FFFFF
	orl	%ecx, %eax
	movl	-60(%ebp), %ecx         # 4-byte Reload
	movl	%eax, 4(%ecx)
	movl	16(%ebp), %eax
	decl	%eax
	movl	%eax, 16(%ebp)
	movl	-16(%ebp), %eax
	movl	4(%eax), %eax
	shrl	$23, %eax
	andl	$1, %eax
	cmpl	$0, %eax
	movl	%ebx, -64(%ebp)         # 4-byte Spill
	movl	%edx, -68(%ebp)         # 4-byte Spill
	movl	%esi, -72(%ebp)         # 4-byte Spill
	movl	%edi, -76(%ebp)         # 4-byte Spill
	je	.LBB5_2
# %bb.1:
	movl	16(%ebp), %eax
	shrl	$12, %eax
	movl	%eax, 16(%ebp)
.LBB5_2:
	movl	-16(%ebp), %eax
	movl	28(%ebp), %ecx
	movl	4(%eax), %edx
	andl	$1, %ecx
	shll	$15, %ecx
	andl	$-32769, %edx           # imm = 0xFFFF7FFF
	orl	%ecx, %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	movl	36(%ebp), %ecx
	movl	4(%eax), %edx
	andl	$1, %ecx
	shll	$12, %ecx
	andl	$-4097, %edx            # imm = 0xEFFF
	orl	%ecx, %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	movl	40(%ebp), %ecx
	movl	4(%eax), %edx
	movl	%ecx, %esi
	andl	$15, %esi
	shll	$8, %esi
	andl	$-3841, %edx            # imm = 0xF0FF
	orl	%esi, %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	movl	4(%eax), %edx
	andl	$1, %ecx
	shll	$20, %ecx
	andl	$-1048577, %edx         # imm = 0xFFEFFFFF
	orl	%ecx, %edx
	movl	%edx, 4(%eax)
	movb	15(%ebp), %bl
	movl	-16(%ebp), %eax
	movb	%bl, 7(%eax)
	movl	12(%ebp), %eax
	movl	-16(%ebp), %ecx
	movzwl	(%ecx), %edx
	movl	%eax, %esi
	shrl	$16, %esi
	movl	%esi, %ebx
                                        # kill: def %bl killed %bl killed %ebx
	shll	$16, %eax
	orl	%eax, %edx
	movl	%edx, (%ecx)
	movb	%bl, 4(%ecx)
	movl	-16(%ebp), %eax
	movzwl	18(%ebp), %ecx
	movl	4(%eax), %edx
	andl	$15, %ecx
	shll	$16, %ecx
	andl	$-983041, %edx          # imm = 0xFFF0FFFF
	orl	%ecx, %edx
	movl	%edx, 4(%eax)
	movw	16(%ebp), %di
	movl	-16(%ebp), %eax
	movw	%di, (%eax)
	addl	$64, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.Lfunc_end5:
	.size	"描述符_创建m", .Lfunc_end5-"描述符_创建m"
                                        # -- End function
	.globl	"gdt建立"             # -- Begin function gdt建立
	.p2align	4, 0x90
	.type	"gdt建立",@function
"gdt建立":                            # @"gdt\E5\BB\BA\E7\AB\8B"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$92, %esp
	movl	$16777216, %eax         # imm = 0x1000000
	movl	$4294963200, %ecx       # imm = 0xFFFFF000
	movl	$1, %edx
	xorl	%esi, %esi
	movl	$10, %edi
	movl	$16781312, %ebx         # imm = 0x1001000
	movl	%ebx, -16(%ebp)
	movl	-16(%ebp), %ebx
	addl	$8, %ebx
	movl	%ebx, (%esp)
	movl	$16777216, 4(%esp)      # imm = 0x1000000
	movl	$-4096, 8(%esp)         # imm = 0xF000
	movl	$1, 12(%esp)
	movl	$0, 16(%esp)
	movl	$1, 20(%esp)
	movl	$1, 24(%esp)
	movl	$1, 28(%esp)
	movl	$10, 32(%esp)
	movl	%eax, -20(%ebp)         # 4-byte Spill
	movl	%ecx, -24(%ebp)         # 4-byte Spill
	movl	%edx, -28(%ebp)         # 4-byte Spill
	movl	%esi, -32(%ebp)         # 4-byte Spill
	movl	%edi, -36(%ebp)         # 4-byte Spill
	calll	"描述符_创建m"
	movl	$16777216, %eax         # imm = 0x1000000
	movl	$4294963200, %ecx       # imm = 0xFFFFF000
	movl	$1, %edx
	xorl	%esi, %esi
	movl	$2, %edi
	movl	-16(%ebp), %ebx
	addl	$16, %ebx
	movl	%ebx, (%esp)
	movl	$16777216, 4(%esp)      # imm = 0x1000000
	movl	$-4096, 8(%esp)         # imm = 0xF000
	movl	$1, 12(%esp)
	movl	$0, 16(%esp)
	movl	$1, 20(%esp)
	movl	$1, 24(%esp)
	movl	$1, 28(%esp)
	movl	$2, 32(%esp)
	movl	%eax, -40(%ebp)         # 4-byte Spill
	movl	%ecx, -44(%ebp)         # 4-byte Spill
	movl	%edx, -48(%ebp)         # 4-byte Spill
	movl	%esi, -52(%ebp)         # 4-byte Spill
	movl	%edi, -56(%ebp)         # 4-byte Spill
	calll	"描述符_创建m"
	addl	$92, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.Lfunc_end6:
	.size	"gdt建立", .Lfunc_end6-"gdt建立"
                                        # -- End function
	.globl	"启动"                # -- Begin function 启动
	.p2align	4, 0x90
	.type	"启动",@function
"启动":                               # @"\E5\90\AF\E5\8A\A8"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$16777216, %eax         # imm = 0x1000000
	movl	$4194304, %ecx          # imm = 0x400000
	movl	%eax, (%esp)
	movl	$4194304, 4(%esp)       # imm = 0x400000
	movl	%ecx, -4(%ebp)          # 4-byte Spill
	calll	"mem_清零"
	calll	"页初始化"
	calll	"gdt建立"
	movl	$16777216, %eax         # imm = 0x1000000
	movl	$16777216, (%esp)       # imm = 0x1000000
	movl	%eax, -8(%ebp)          # 4-byte Spill
	calll	"页_设置cr3_"
	calll	"页_开启_"
	movl	$8192, %eax             # imm = 0x2000
	movl	$16781312, %ecx         # imm = 0x1001000
	movl	$8192, (%esp)           # imm = 0x2000
	movl	%ecx, 4(%esp)
	movl	%eax, -12(%ebp)         # 4-byte Spill
	calll	"GDTR_设置_"
.LBB7_1:                                # =>This Inner Loop Header: Depth=1
	jmp	.LBB7_1
.Lfunc_end7:
	.size	"启动", .Lfunc_end7-"启动"
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function 页_设置cr3_
	.type	"页_设置cr3_",@function
"页_设置cr3_":                       # @"\E9\A1\B5_\E8\AE\BE\E7\BD\AEcr3_"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%eax
	movl	8(%ebp), %eax
	#APP
	movl	8(%ebp), %eax
	movl	%eax, %cr3

	#NO_APP
	movl	%eax, -4(%ebp)          # 4-byte Spill
	addl	$4, %esp
	popl	%ebp
	retl
.Lfunc_end8:
	.size	"页_设置cr3_", .Lfunc_end8-"页_设置cr3_"
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function GDTR_设置_
	.type	"GDTR_设置_",@function
"GDTR_设置_":                         # @"GDTR_\E8\AE\BE\E7\BD\AE_"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	subl	$20, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	8(%ebp), %edx
	subl	$1, %edx
	movw	%dx, %si
	movw	%si, -16(%ebp)
	movl	12(%ebp), %edx
	movl	%edx, -14(%ebp)
	#APP
	lgdtl	-16(%ebp)


	#NO_APP
	movl	%eax, -20(%ebp)         # 4-byte Spill
	movl	%ecx, -24(%ebp)         # 4-byte Spill
	addl	$20, %esp
	popl	%esi
	popl	%ebp
	retl
.Lfunc_end9:
	.size	"GDTR_设置_", .Lfunc_end9-"GDTR_设置_"
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function 页_开启_
	.type	"页_开启_",@function
"页_开启_":                          # @"\E9\A1\B5_\E5\BC\80\E5\90\AF_"
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	#APP
	movl	%cr0, %eax

	orl	$2147483648, %eax       # imm = 0x80000000

	movl	%eax, %cr0


	#NO_APP
.LBB10_1:                               # =>This Inner Loop Header: Depth=1
	jmp	.LBB10_1
.Lfunc_end10:
	.size	"页_开启_", .Lfunc_end10-"页_开启_"
                                        # -- End function

	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
