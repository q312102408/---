#include "j基础类型.h"
#include "内核文件分布图.h"
//页目录和页表长相一样，属于一样。均有4k大小，有1024个项
// u_s用户1/系统访问权限0。1/0   w_r 读写保护位，0只读，1读写，p存在位
static void 页_建立(void *页, uint 地址, int u_s, int w_r) { //页位置 指向地址
  unsigned int *z = 页;
  *z = 地址 & (~4095);

  *z += 1;
  if (u_s)
    *z += 4;
  if (w_r)
    *z += 2;

  //输出链("zzzzzzz", (uint)页, (uint)地址);
}
static uint 取实地址(void *页目录地址, void *目标地址) {
  //已测试,吴bug
  uint *a = 页目录地址;
  uint b = 目标地址;

  a = (uint *)(a[b >> 22] & (~4095));

  b = (a[(b >> 12) % 1024] & (~4095));

  return b + ((uint)目标地址 & 4095);
}
static void 删除(void *页目录地址, void *目标地址) {}
//页目录和页表长相一样，属于一样。均有4k大小，有1024个项
// u_s用户1/系统访问权限0。1/0   w_r 读写保护位，0只读，1读写，p存在位
static void 添加(void *页目录地址, void *目标地址, uint 物理地址, int u_s,
                 int w_r) {
  uint *a = 页目录地址;
  uint b = (uint)目标地址;
  //页表是否为空
  if ((uint)a % h_一页大小 != 0) {
    输出链("dizhibushiyiyedaxiao:", (uint)a, "ye_tianjia", __LINE__);
    a = (uint *)((*a) & (~4095));
  }
  输出链("-", *a, b);
  a = a + (b >> 22);
  输出链(*a);
  if (*a == 0) {
    //要创建新的页表
    检查(*a);
  }
  //指向页表
  a = (uint *)((*a) & (~4095));
  a = a + ((b >> 12) % 1024);

  if (*a != 0) {
    //删除旧的指向
    //检查(a[(((uint)b) >> 12) & 0x3ff]);
  }
  输出链((uint)a);
  页_建立(a, 物理地址, u_s, w_r);
}

struct {
  void (*添加)(void *页目录地址, void *目标地址, uint 物理地址, int u_s,
               int w_r);
  void (*删除)(void *页目录地址, void *目标地址);
  uint (*取实地址)(void *页目录地址, void *目标地址);
} 页 = {.添加 = 添加, .删除 = 删除, .取实地址 = 取实地址};
