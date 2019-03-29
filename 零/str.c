#include "j基础类型.h"






void mem_复制(void *a_, const void *b_,uint 长度)
{
    //如果会被覆盖
    if ((int)a_ > (int)b_ && (int)a_-长度 < (int)b_)
{
   
    char *a = a_+长度;
    const char *b = b_+长度;
    
    while (长度--)
    {
        *a = *b;
        a--, b--;
    }
    return;
}

    char *a = a_;
    const char *b = b_;

    while(长度--)
    {
        *a = *b;
        a++,b++;
    }

}

void mem_设置(void *a_, uint 长度,char 值 )
{
    char *a = a_;
    
    while(长度--){
       *a=值;
       a++;
    }
    
}
void mem_清零(void *a_, uint 长度 )
{
    mem_设置(a_, 长度, 0);
}

uint str_取长度(const void *a_)
{
    const char *a = a_;
    uint b = 0;
    while (*a)
    {

        a++;
        b++;
    }
    return b;
}
void str_复制(void *a_, const void *b_)
{
    //尾部的0也复制
    mem_复制(a_, b_, str_取长度(b_) + 1);
}
//返回错误位置,-1为相等
int mem_对比_(const void *a_,  const void *b_, uint 长度)
{
    const uchar *a = a_;
    const uchar *b = b_;
    while (长度--)
    {
        if(*a++!=*b++)
        {
            return((uint)a-(uint)a_);
        }
    }
    return -1;
}
//返回匹配位置,如果没匹配 返回-1
int mem_寻找char(const void *a_, uint a的长度,char b)
{
    const uchar *a = a_;
    
    for(uint i = 0; i < a的长度; i++)
    {
        if(a[i]==b) return i;
    }
    return -1;
    
}
//找不到返回-1
int mem_寻找(const void *a_,int a的长度,const void *b_,int b的长度)
{
    const uchar *a = a_;
    const uchar *b = b_;
    int 起点 = 0;
    a的长度 -= b的长度;
    int 错误点;
    while (a的长度>=起点)
    {
        错误点= mem_对比_(a+ 起点 ,b, b的长度);
        if(错误点==-1)
        {
            return 起点;
        }
       起点++;
        错误点=mem_寻找char(a + 起点, a的长度 - 起点,b[ 错误点 ]);
        起点+= 错误点;
   }
    return -1;
}


int 取utf8中文长度(const char *a_)
{
    uchar a = *a_;
    uint b=0;
    if(a<128)b=1;
    if (a < 128)
       return 1;
    if (a < 192)//  没有0b10开头的
        return 0;
    if (a < 224)
        return 2;
    if (a < 240)
        return 3;
    if (a < 248)
        return 4;
    if (a < 252)
        return 5;
    if (a < 254)
        return 6;
    return 7;

}

/*
 char *中文库 = ",的de,";
   //返回取出的数量,错误位0
int  取拼音(const void *a_, void *储存位置, uint 位置大小)
{

    uchar * a=(uchar *)a_;
    uchar *b=储存位置;
    
    if(*a<128)
    {
        if (位置大小 > 0)
        {
           *b=*a; 
        }
        return 1;
    }
   

    int 中文长度 =取utf8中文长度(a);
    if(中文长度 ==-1) return 0;
    uchar c[10]=",";
    mem_复制 ( c,a,中文长度);
   int z= mem_寻找(中文库, sizeof(中文库), c, 中文长度);
    if(z==-1) return 0;
    z+= 中文长度;
    int x = mem_寻找char(中文库 + z, 10, ',');
    mem_复制 ( 储存位置, 中文库+z, x-z);
    ((char*) 储存位置)[x - z]=0;
    return 中文长度;
}



*/
