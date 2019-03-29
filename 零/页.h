
#ifndef _页_h_
#define _页_h_
#include "j基础类型.h"
extern struct
{
    void (*添加)(void *页目录地址, void *目标地址, uint 物理地址, int u_s, int w_r);
    void (*删除)(void *页目录地址, void *目标地址);
    uint (*取实地址)(void *页目录地址, void *目标地址);
} 页;

#endif
