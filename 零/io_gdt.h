
#define io_eflags_读取()                                                       \
  ({                                                                           \
    uint data;                                                                 \
    asm("pushfl;pop %0;" : "=a"(data) :);                                      \
    data;                                                                      \
  })
#define io_eflags_设置(eflags) ({ asm("pushl %0;popfl" ::"a"(eflags)); });

#ifndef _io_gdt_h_
#define _io_gdt_h_
#include "j基础类型.h"

void 描述符_创建m(void *地址d, uint 段基址d, uint 段大小d, uint 颗粒度_G位k,
                  uint 特权级t, uint 段是否存在, uint 是否32位s,
                  uint 是否非系统段s, uint 段类型d);
void GDT_初始化();
void GDT_选择(uint 位置, int 不在gdt中, int 特权级);
void GDT_选择内存(uint 位置, int 不在gdt中, int 特权级);
void GDT_选择栈(uint 位置, int 不在gdt中, int 特权级);
void GDTR_设置(uint 大小, uint 地址);
uint GDTR_读取();

void idt_初始化();

void IDTR_设置(uint 大小, uint 地址);
uint IDTR_读取();
void io_写入8位(uint 端口, uint 数据);
void io_写入串(uint 端口, const void *数据, uint 长度);
uchar io_读取8位(uint 端口);
void io_读取串(uint 端口, void *数据, uint 长度);
// void io_eflags_设置(uint eflags);
// uint io_eflags_读取();
void 页_开启();
void 页_设置cr3(uint 地址);
void io_hlt();
void io_禁止中断();
void io_开启中断();

// void zongtizhongduan();

#endif