#include "j基础类型.h"
#ifndef __string__
#define __string__


uint str_取长度(const void *a_);
void str_复制(void *a_, const void *b_);
void mem_复制(void *a_, const void *b_, uint 长度); 
void mem_设置(void *a_, uint 长度, char 值);
void mem_清零(void *a_, uint 长度);
int 取拼音(const void *a_, void *储存位置, uint 位置大小);
int 取utf8中文长度(const char *a_);
int mem_寻找(const void *a_, int a的长度, const void *b_, int b的长度);

#endif


