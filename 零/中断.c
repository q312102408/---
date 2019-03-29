#include "io_gdt.h"
#include "j基础类型.h"
#include "str.h"
#include "内核文件分布图.h"

struct IDT {
  unsigned 中断位置0_15 : 16, 选择子 : 16, 无用 : 8, 类型 : 4, S : 1, DPL : 2,
      p : 1, 中断位置24_31 : 16;
} __attribute__((packed));
extern void 页_建立_临时(void *页, int 地址, int u_s, int w_r);
extern uint *__wgy__shu;
extern uint *__wgy_linshi;
extern void _hint00();
extern void _hint01();
extern void _hint0x();

static uint *a的地址 = 0;
static struct IDT *idt_地址 = 0;
static struct {
  uint 端口号;
  void (*函数)();
} * 中断列表;
#define 中断列表个数 60
#define 中断错误起点 40

static void pic_初始化() {
  //关闭所有中断
  io_写入8位(0x21, 0xff);
  io_写入8位(0xa1, 0xff);

  io_写入8位(0x20, 0x11);   /* 边沿触发 */
  io_写入8位(0x21, 0x20);   /* IRQ0-7由INT20-27接受 */
  io_写入8位(0x21, 1 << 2); /* PIC1由IRQ2连接 */
  io_写入8位(0x21, 0x01);   /* 无缓冲模式 */
  //与上类似
  io_写入8位(0xa0, 0x11); /* �G�b�W�g���K���[�h */
  io_写入8位(0xa1, 0x28); /* IRQ8-15�́AINT28-2f�Ŏ󂯂� */
  io_写入8位(0xa1, 2);    /* PIC1��IRQ2�ɂĐڑ� */
  io_写入8位(0xa1, 0x01); /* �m���o�b�t�@���[�h */

  io_写入8位(0x21, 0xfd); //禁止所有中断
  io_写入8位(0xa1, 0xff); /* 11111011 PIC1以外全部禁止 */
}

static uint idt_创建(struct IDT *地址, uint 中断函数位置, uint 选择子) {
  uint a = 地址->中断位置0_15 + (地址->中断位置24_31 << 16);
  地址->无用 = 0;
  地址->类型 = 14;
  地址->DPL = 0;
  地址->选择子 = 选择子;
  地址->中断位置0_15 = 中断函数位置 & 0xffff;
  地址->中断位置24_31 = 中断函数位置 >> 16;
  地址->S = 0;
  地址->p = 1;
  return a;
}
void _zongtizhongduan(uint a) {
  a的地址 = &a;

  中断列表[a].函数();

  //死循环(1);
  a的地址 = 0;
}

h宏_中断 void _hint0z() {

  // io_写入8位(0x21, 0xff); //禁止所有中断
  // io_写入8位(0xa1, 0xff);
  // io_写入8位(0x20, 0x61);

  输出十六位(io_读取8位(0x60));
  io_写入8位(0x20, 0x20);
  // io_写入8位(0xa0, 0x20);
  输出链("zz");

  io_开启中断();

  ;

  //死循环("z666");
}

uint 注册中断(uint 端口号, uint 函数地址, int 是否有错误码) {

  uint a, b;
  if (是否有错误码 == 0) {
    a = 0;
    b = 中断错误起点;
  } else {
    a = 中断错误起点;
    b = 中断列表个数;
  }
  //以前注册过
  for (uint i = a; i < b; i++) {
    if (中断列表[i].端口号 == 端口号) {
      中断列表[i].函数 = 函数地址;
      return idt_创建(idt_地址 + 端口号,
                      (uint)_hint00 + ((uint)_hint01 - (uint)_hint00) * i,
                      1 * 8);
    }
  }
  //没有注册过
  for (uint i = a; i < b; i++) {
    if (中断列表[i].端口号 == 0) {

      中断列表[i].函数 = 函数地址;
      中断列表[i].端口号 = 端口号;
      return idt_创建(idt_地址 + 端口号,
                      (uint)_hint00 + ((uint)_hint01 - (uint)_hint00) * i,
                      1 * 8);
    }
  }

  输出链("duankouzhuceshibai");
  return 0;
}
uint 取中断端口() {
  if (a的地址 != 0)
    return 中断列表[*a的地址].端口号;
}

void 键盘测试() { 输出十六位(io_读取8位(0x60)); }
void 内部中断注册();

void idt_初始化() {
  pic_初始化();
  uint a = 内存.申请一页();

  页_建立_临时(h_内核页表_起点 + (a >> 12) * 4, a, 0, 1);
  idt_地址 = a + h_虚拟地址起点;

  mem_清零(idt_地址, 一页大小);

  /* for (int i = 0; i < 255; i++) {
     idt_创建(idt_地址 + i, (uint)_hint00 + ((uint)_hint01 - (uint)_hint00) * i,
              1 * 8);
     // idt_创建(idt_地址 + i, (uint)_hint0x, 1 * 8);
     // idt_创建(idt_地址 + i, (uint)_hint01, 1 * 8);
   }
   idt_创建(idt_地址 + 6, (uint)_hint01, 1 * 8);
 */
  //低位已经够用,高位放此
  中断列表 = (uint)idt_地址 + 2048;

  IDTR_设置(一页大小, (uint)a);

  注册中断(0x21, 键盘测试, 0);
  内部中断注册();
  io_开启中断();
}

struct 中断 {
  uint (*注册中断)(uint 端口号, uint 函数地址, int 是否有错误码);
  uint (*取中断端口)();

} 中断 = {.注册中断 = 注册中断, .取中断端口 = 取中断端口};
void 内部中断集合() {

  switch (取中断端口()) {
  case 0: //除法错
    输出链("");
    break;
  case 1: //调试异常
    输出链("");
    break;
  case 2: //非屏蔽中断
    输出链("");
    break;
  case 3: //调试断点
    输出链("");
    break;
  case 4: //溢出
    输出链("");
    break;
  case 5: //越界
    输出链("");
    break;
  case 6: //无效指令
    输出链("");
    break;
  case 7: //无数学协处理器
    输出链("");
    break;
  case 8: //双重错误
    输出链("");
    break;
  case 9: //协处理器越界
    输出链("");
    break;
  case 10: //无效tss
    输出链("");
    break;
  case 11: //段不存在
    输出链("");
    break;
  case 12: //堆栈段错误
    输出链("");
    break;
  case 13: //常规保护错误
    输出链("");
    break;
  case 14: //页错误
    输出链("");
    break;
  case 16: // x87fpu错误
    输出链("");
    break;
  case 17: //对其校验
    输出链("");
    break;
  case 18: // machine check
    输出链("");
    break;
  case 19: // simd 浮点异常
    输出链("");
    break;

  default:
    break;
  }

  输出链("nei bu cuo wu .", 取中断端口(), "<<|||");
  死循环("neibuzhuduan");
}
void 内部中断注册() {
  注册中断(0x0, 内部中断集合, 0);
  注册中断(0x1, 内部中断集合, 0);
  注册中断(0x2, 内部中断集合, 0);
  注册中断(0x3, 内部中断集合, 0);
  注册中断(0x4, 内部中断集合, 0);
  注册中断(0x5, 内部中断集合, 0);
  注册中断(0x6, 内部中断集合, 0);
  注册中断(0x7, 内部中断集合, 0);
  注册中断(0x8, 内部中断集合, 1);
  注册中断(0x9, 内部中断集合, 0);
  注册中断(10, 内部中断集合, 1);
  注册中断(11, 内部中断集合, 1);
  注册中断(12, 内部中断集合, 1);
  注册中断(13, 内部中断集合, 1);
  注册中断(14, 内部中断集合, 1);
  注册中断(16, 内部中断集合, 0);
  注册中断(17, 内部中断集合, 1);
  注册中断(18, 内部中断集合, 0);
  中断.注册中断(19, 内部中断集合, 0);
}

/*
0x20 时钟中断
0x21 键盘中断
0x22 级联用的
0x26 软盘对应的入口
0x28  实时时钟对应入口
0x29 重定向
0x2c  鼠标
0x2e  硬盘
*/