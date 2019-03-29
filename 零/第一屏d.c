#include "j基础类型.h"
#include "str.h"
#include "内核文件分布图.h"
/*0xB8000
    0xB8FA0
*/
#define 第一屏地址起点 (h_虚拟地址起点 + 0xB8000)

static uchar *起点 = (uchar *)第一屏地址起点;

static void 输出_(uchar a)
{
    * 起点=a;
    起点+=2;
    if ((int)起点 > 0xFA0 + 第一屏地址起点)
        起点 = (uchar *)第一屏地址起点;
}

static void _绝对内部(int a)
{
    if(a<10)
    {   if(a>0)
            输出_( 字符集[a] );
        return ;
    }
    _绝对内部(a/10);
    输出_(字符集[a%10]);
}

static void 输出整数_(int a)
{
    if(a<0){
        输出_('-');
       a=-a;
    }
     if (a>9)
    {
        _绝对内部(a);    
    }else
    输出_(字符集[a]);
    输出_(' ');
}
static void 输出十六进制通用_(void *a, uint 大小d_)
{
    
    uchar *a1=a;
    
    while(大小d_)
    {
        uchar e = *a1;
        输出_(字符集[e >> 4]);
        输出_(字符集[e & 0xf]);
        输出(" ");
        a1++;
        大小d_--;
    }
    输出_(' ');
}

void 输出十六进制通用_1(void *a, uint 大小d_)
{
    输出十六进制通用_(a,  大小d_);
}

//数字类只能执行这个,在x86的情况下
static void 输出十六进制逆序通用_(void *a, uint 大小d_)
{

    uchar *a1 = a+大小d_-1;
    while (大小d_)
    {
        uchar e = *a1;
        输出_(字符集[e >> 4]);
        输出_(字符集[e & 0xf]);
        a1--;
        大小d_--;
    }
    输出_(' ');
}
//原版
static void 输出字符串_(char *a)
{
    while (*a)
    {
        输出_(*a);
        a++;
    }
    输出_(' ');
}
//输出中文型
static void 输出字符串_1(char *a)
{
    char b[10];
    while (*a)
    {
        int d =取拼音(a,b,10);
        if(d==0)
        {
            a++;
            输出_(2);
        }else
        {
            输出字符串_1(b);
            a+=d;
        }
        
    }
    输出_(' ');
}

static void 输出十六位整数_(int a)
{

    输出十六进制逆序通用_(&a, sizeof(a));
    输出_(' ');
}

 void 第一屏_初始化()
{
    起点 = (uchar *)第一屏地址起点;
    屏幕.输出十六位= 输出十六位整数_;
    屏幕.输出十六位指针=输出十六进制通用_;
    屏幕.输出字符 = 输出_;
    屏幕.输出字符串 = 输出字符串_;
    屏幕.输出整数 = 输出整数_ ;

   
}

