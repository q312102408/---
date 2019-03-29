#ifndef _物理内存_h_
#define _物理内存_h_
#include "j基础类型.h"


int 物理内存_取可用空间();
void 物理内存_占用(uint 起点, uint 长度);
uint *物理内存_申请(uint 大小_);
uint *物理内存_申请一页();
void 物理内存_删除一页(uint *a);
void 物理内存_删除(uint *a_, uint b);
void 物理内存_占用一页(uint *a);
int 物理内存_页是否被占用(uint *a);
void 物理内存_输出剩余空间();
void 物理内存_初始化();
;
;

#endif