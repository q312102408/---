#include "j基础类型.h"
#include "str.h"

extern int _hint00, _hint01;
struct GDT1 {
  unsigned 段界限d0_15 : 16, 段基址d0_23 : 24, 段类型d : 4, S : 1, DPL : 2,
      p : 1, 段界限d16_19 : 4, AVL : 1, 空 : 1, D_B : 1, G颗粒度 : 1,
      段基址24_31 : 8;
} __attribute__((packed));

//          S=1时
//段类型说明 0只读,2读写,4向下扩展,只读,6 向下扩展,读写
//         8仅执行,10执行,可读 12一致性代码段,仅执行,14 一致性代码段,执行,可读
//  s=0时,为系统段 .局部描述符表的段描述符,任务段,调用门12,中断门,任务门,陷阱门
void 描述符_创建m(void *地址d, uint 段基址d, uint 段大小d, uint 颗粒度_G位k,
                  uint 特权级t, uint 段是否存在, uint 是否32位s,
                  uint 是否非系统段s, uint 段类型d) {

  mem_清零(地址d, sizeof(struct GDT1));
  struct GDT1 *g = 地址d;
  g->DPL = 特权级t;
  g->D_B = 是否32位s;
  g->G颗粒度 = 颗粒度_G位k;
  段大小d--;
  if (g->G颗粒度)
    段大小d /= 4096;
  g->p = 段是否存在;
  g->S = 是否非系统段s;
  g->AVL = g->段类型d = 段类型d;
  g->段基址24_31 = 段基址d >> 24;
  g->段基址d0_23 = 段基址d & 0xffffff;
  g->段界限d16_19 = 段大小d >> 16;
  g->段界限d0_15 = 段大小d & 0xffff;
}
void 创建_系统段(void *地址, uint 段基址, uint 段大小) {}

void 创建_段(void *地址, uint 段基址, uint 段大小) {}
void GDTR_设置(uint 大小, void *地址);

struct GDT1 *gdt_地址 = 0;

void GDT_初始化() {
  gdt_地址 = 内存.申请一页();
  if (gdt_地址 > 0) {

    mem_清零(gdt_地址, 一页大小);

    描述符_创建m(gdt_地址 + 1, 0, 0xfffff000, 1, 0, 1, 1, 1, 10);
    描述符_创建m(gdt_地址 + 2, 0, 0xfffff000, 1, 0, 1, 1, 1, 2);
    GDTR_设置(一页大小, gdt_地址);
  }

  ;
}

void GDT_选择(uint 位置, int 不在gdt中, int 特权级) {
  位置 = 位置 << 3;
  if (不在gdt中)
    位置 += 4;
  if (特权级 > 3)
    特权级 = 3;
  位置 += 特权级;
  // asm(" ljmp  %0: $next;\n next :	\n "::"a"(位置));
  //目前无法实现
}

void GDT_选择内存(uint 位置, int 不在gdt中, int 特权级) {

  位置 = 位置 << 3;
  if (不在gdt中)
    位置 += 4;
  if (特权级 > 3)
    特权级 = 3;
  位置 += 特权级;
  asm("movl 8(%ebp),%eax;\
	movl %eax,%ds ; \
	movl %eax,%fs ; \
	movl %eax,%gs ; \
	movl %eax,%es");
}
void GDT_选择栈(uint 位置, int 不在gdt中, int 特权级) {

  位置 = 位置 << 3;
  if (不在gdt中)
    位置 += 4;
  if (特权级 > 3)
    特权级 = 3;
  位置 += 特权级;
  asm("movl 8(%ebp), % esp;");
}

#pragma pack(push) // 将当前pack设置压栈保存
#pragma pack(2)    // 必须在结构体定义之前使用
struct {
  unsigned short 大小;
  unsigned int 地址;
} 结构体1;
#pragma pack(pop)

void GDTR_设置(uint 大小, void *地址) {

  结构体1.大小 = 大小 - 1;
  结构体1.地址 = (uint)地址;
  asm("lgdt %0;\n" ::"m"(结构体1));
}
void IDTR_设置(uint 大小, void *地址) {

  结构体1.大小 = 大小 - 1;
  结构体1.地址 = (uint)地址;
  asm("lidt %0;\n" ::"m"(结构体1));
}

struct GATE_DESCRIPTOR {
  short offset_low, selector;
  char dw_count, access_right;
  short offset_high;
};
void set_gatedesc(struct GATE_DESCRIPTOR *gd, int offset, int selector,
                  int ar) {
  gd->offset_low = offset & 0xffff;
  gd->selector = selector;
  gd->dw_count = (ar >> 8) & 0xff;
  gd->access_right = ar & 0xff;
  gd->offset_high = (offset >> 16) & 0xffff;
  return;
}
uint IDTR_读取() {

  asm("sidt %0;\n" : "=m"(结构体1) :);
  return 结构体1.地址;
}
uint GDTR_读取() {

  asm("sgdt %0;\n" : "=m"(结构体1) :);
  return 结构体1.地址;
}

void io_禁止中断() { asm("cli;"); }
void io_开启中断() { asm("sti;"); }

void io_写入8位(short port, char a) {

  asm("outb %b0,%w1;" : : "a"(a), "Nd"(port));
}
void io_写入串(uint 端口, const void *数据, uint 长度) {

  asm("cld;rep outsb;" : "+S"(数据), "+c"(长度) : "d"(端口));
}
uchar io_读取8位(uint 端口) {
  uchar data;
  asm("inb %w1,%b0" : "=a"(data) : "Nd"(端口));
  return data;
}

void io_读取串(uint 端口, void *数据, uint 长度) {
  asm("cld;rep insb" : "+D"(数据), "+c"(长度) : "d"(端口) : "memory");
}

void io_eflags_设置(uint eflags) { asm("pushl %0;popf" ::"a"(eflags)); }
uint io_eflags_读取() {
  //方式1
  /* asm("pushfl;popl %eax;addl	$4, %esp;\
       popl	%ebp;\
       retl;");
   return 0;
   */

  //方式2
  uint data = 0;
  asm("pushf;popl %0;" : "=a"(data) :);
  return data;
}

void 页_开启() {
  asm("movl %cr0,%eax;\
		orl $0x80000000,%eax;\
		movl %eax,%cr0;\
		");
}
void 页_设置cr3(uint 地址) {
  asm("movl 8(%ebp),%eax;\
		movl %eax,%cr3;");
}

void io_hlt() { asm("hlt;"); }
