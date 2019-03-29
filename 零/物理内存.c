#include "j基础类型.h"
#include "str.h"
#include "内核文件分布图.h"
#include "页.h"
static uchar *位置;
static uint 大小;
uint 物理大小;
extern void 页_建立_临时(void *页, int 地址, int u_s, int w_r);
//寻找地址起点总是从64k开始的

//实际空间,以后再处理
static uint 取实际空间大小() { return 32 * 1024 * 1024; }

int 取可用空间() {
  int b = 0;
  for (uint i = 64; i < 大小; i++) {
    if (位置[i] == 0) {
      b++;
    }
  }
  return b;
}

static void 已经被占用的(uint 起点, uint 长度) {

  长度 = (起点 + 长度 + 一页大小 - 1);
  长度 /= 一页大小;
  起点 /= 一页大小;

  长度 -= 起点;

  mem_设置(位置 + 起点, 长度, 1);

  //输出链("keyongkongjian:", 取可用空间());
}

static uint *申请(uint 大小_) {

  大小_ = 大小_ + 一页大小 - 1;
  大小_ /= 一页大小;
  int b = 0;
  for (uint i = 64; i < 大小 - 大小_; i++) {
    if (位置[i] == 0) {
      uint m = i;
      for (uint a = 大小_ - 1; a; a--) {
        m++;
        if (位置[m] != 0)
          goto over;
      }
      //运行到这里说明匹配成功了

      mem_设置(位置 + i, 大小_, 1);

      return (uint *)(i * 一页大小);
    }
  over:;
  }
  return 0;
}

static uint *申请一页() { return (申请(一页大小)); }
static void 删除一页(uint *a) {
  uint c = (uint)a;
  c /= 一页大小;
  if (位置[c] > 0) {
    位置[c]--;
  }
}
static void 删除(uint *a_, uint b) {

  uint d = ((uint)b + 一页大小 - 1) / 一页大小;

  uint a = (uint)a_;
  while (d--) {
    删除一页((uint *)a);
    a += 一页大小;
  }
}

static void 占用一页(uint *a) {
  uint c = (uint)a;
  c /= 一页大小;
  if (位置[c] < 200) {
    位置[c]++;
  }
}
static int 页是否被占用(uint *a) {
  uint c = (uint)a;
  c /= 一页大小;

  return 位置[c];
}
static void 输出剩余空间() {
  输出链("haiyou", 取可用空间(), "*4096 daxiaokeyong");
}

void 物理内存_初始化() {

  内存.申请 = 申请;
  内存.申请一页 = 申请一页;
  内存.删除一页 = 删除一页;
  内存.占用一页 = 占用一页;
  内存.页是否占用 = 页是否被占用;
  内存.删除 = 删除;
  内存.输出剩余空间 = 输出剩余空间;
  //直接使用低位真实空间进行地点处理

  位置 = h_物理地址空白区;
  大小 = 物理大小;

  大小 /= 一页大小;

  for (int i = 0; i <= 大小; i += h_一页大小) {

    页_建立_临时(h_内核页表_起点 + ((h_物理地址空白区 >> 12)) * 4 + (i >> 10),
                 ((uint)位置) + i, 0, 1);
  }

  位置 += h_虚拟地址起点;

  // 死循环(20);
  mem_清零(位置, 大小 - 0x1f00);
  //死循环("z");
  //自身所被占用的
  已经被占用的(((uint)位置) / 4096, 大小);
  //处理已经被占用的区域

  已经被占用的(0, h_物理地址空白区);

  输出剩余空间();
}
