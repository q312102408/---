#include "j基础类型.h"

#include "str.h"
#include "内核文件分布图.h"

void 内核初始化();
extern uint 物理大小;
static void 启动();

void _start(void) {

  启动();

  while (1) {
  }
  return;
}

static void 输出1(int shu) {
  char *b = 0xB8000;
  // while (1)
  {
    *b = shu;
    *b = ' ';
    *b = shu;
  };
}

static uint 计算物理大小() {
  uchar *b = (uchar *)h_内核目录_实地址;
  uchar a;
  while ((uint)b < 0x7fffffff) {
    a = *b;
    *b = a + 1;
    if (*b == a + 1) {
      *b = a;
      b += 1024 * 1024 * 45;

    } else {
      b -= 1024 * 1024 * 45;
      // 输出((int)b);
      break;
    }
  }
  //输出((int)b);
  //上面隔45m计算一次,下面是1m
  while ((uint)b < 0x7fffffff) {
    a = *b;
    *b = a + 1;
    if (*b == a + 1) {
      *b = a;
      b += 1024 * 1024;

    } else {
      b -= 1024 * 1024;
      // 输出((int)b);
      break;
    }
  }

  return (uint)b;
}
//

//页目录和页表长相一样，属于一样。均有4k大小，有1024个项
// u_s用户1/系统访问权限0。1/0   w_r 读写保护位，0只读，1读写，p存在位
void 页_建立_临时(void *页, int 地址, int u_s, int w_r) { //页位置 指向地址
  unsigned int *z = 页;
  *z = 地址 & (~4095);

  *z += 1;
  if (u_s)
    *z += 4;
  if (w_r)
    *z += 2;
}

static void 页初始化() {

  char *页目录 = h_内核目录_实地址;
  char *页表地址 = h_内核页表_起点;

  //页表指向虚拟页

  for (int i = 0; i < h_内核页表个数 * h_一页大小 / 4; i++) {
    页_建立_临时(页表地址 + i * 4, h_一页大小 * i, 0, 1);
  }

  //页目录指向页表
  for (int i = 0; i < h_内核页表个数; i++) {
    页_建立_临时(页目录 + (h_虚拟地址起点 >> 22) * 4 + i * 4,
                 页表地址 + h_一页大小 * i, 0, 1);
  }
  //页目录指向页表,低位空间
  for (int i = 0; i < h_内核页表个数; i++) {
    页_建立_临时(页目录 + i * 4, 页表地址 + h_一页大小 * i, 0, 1);
  }
  //把高位区页表全部建立,后面的的堆/栈就不用考虑页表没有的问题.  --
  //完全为了后期省事
  for (int i = h_内核页表个数; i < h_内核全部页表个数; i++) {
    页_建立_临时(页目录 + (h_虚拟地址起点 >> 22) * 4 + i * 4,
                 页表地址 + h_一页大小 * i, 0, 1);
  }
}
static void 描述符_创建m(void *地址d, uint 段基址d, uint 段大小d,
                         uint 颗粒度_G位k, uint 特权级t, uint 段是否存在,
                         uint 是否32位s, uint 是否非系统段s, uint 段类型d) {
  struct GDT1 {
    unsigned 段界限d0_15 : 16, 段基址d0_23 : 24, 段类型d : 4, S : 1, DPL : 2,
        p : 1, 段界限d16_19 : 4, AVL : 1, 空 : 1, D_B : 1, G颗粒度 : 1,
        段基址24_31 : 8;
  } __attribute__((packed));

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
static void gdt建立() {
  char *gdt地址 = h_gdt_实地址;
  描述符_创建m(gdt地址 + 8 * 1, 0, 0xfffff000, 1, 0, 1, 1, 1, 10);
  描述符_创建m(gdt地址 + 8 * 2, 0, 0xfffff000, 1, 0, 1, 1, 1, 2);
  //描述符_创建m(gdt地址 + 8, h_内核目录_实地址, 0xfffff000, 1, 0, 1, 1, 1, 10);
  //描述符_创建m(gdt地址 + 8 * 1, h_内核目录_实地址, 0xfffff000, 1, 0, 1, 1, 1,
  // 2);
}

static void 页_开启_() {

  asm("movl %%cr0, %%eax  ;\n\t"
      "orl $0x80000000, %%eax      ;\n\t"
      "movl %%eax , %%cr0   ;\n\t"
      :
      :
      :);
}
static void 页_设置cr3_(uint 地址) {
  asm("movl 8(%ebp),%eax;\
		movl %eax,%cr3;");
}

static void GDTR_设置_(uint 大小, void *地址) {

#pragma pack(push) // 将当前pack设置压栈保存
#pragma pack(2)    // 必须在结构体定义之前使用
  struct {
    unsigned short 大小;
    unsigned int 地址;
  } 结构体1;
#pragma pack(pop)

  结构体1.大小 = 大小 - 1;
  结构体1.地址 = (uint)地址;
  asm("lgdt %0;\n" ::"m"(结构体1));
}

static void 启动() {
  int daxiao = 计算物理大小();
  mem_清零(16 * 1024 * 1024, (20 - 16) * 1024 * 1024);

  页初始化();
  gdt建立();
  页_设置cr3_(h_内核目录_实地址);

  GDTR_设置_(gdt_大小, h_gdt_实地址);
  页_开启_();
  物理大小 = daxiao;
  asm("   \
    pushf ;\
    push $8 ;\
    push %0;\
    iret;\
    \
    " ::"r"(内核初始化));
}
