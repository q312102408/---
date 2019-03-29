#include "io_gdt.h"
#include "j基础类型.h"
#include "内核文件分布图.h"
//进入分页了

void 内核初始化() {
  int jubu;

  if ((int)&jubu < h_虚拟地址起点) {

    第一屏_初始化();

    物理内存_初始化();
    idt_初始化();
  }

  输出链("aaa", 123, 568);

  while (1) {
    int a = 15000000;
    while (a--)
      ;
    //输出("-");
  }
}