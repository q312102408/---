#include "j基础类型.h"
char *字符集 = "0123456789ABCDEFGHIJKLMNOPQRST";
__attribute__((overloadable)) void 输出(int a)
{
    屏幕.输出整数(a);
}
__attribute__((overloadable)) void 输出(uint a)
{
    屏幕.输出十六位(a);
}
__attribute__((overloadable)) void 输出(char a)
{
    屏幕.输出字符(a);
}
__attribute__((overloadable)) void 输出(uchar a)
{
    屏幕.输出字符(a);
}
__attribute__((overloadable)) void 输出十六位(int a)
{
    屏幕.输出十六位(a);
    
}
__attribute__((overloadable)) void 输出(char *a)
{
    屏幕.输出字符串(a);
}
__attribute__((overloadable)) void 输出(void *a)
{
    屏幕.输出十六位(a);
}

__attribute__((overloadable)) void 输出十六位(int *a, int 长)
{
    屏幕.输出十六位指针(a, 长);

}