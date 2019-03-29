#define FE1_1(WHAT, X) WHAT(X)
#define FE1_2(WHAT, X, ...) \
    WHAT(X);                \
    FE1_1(WHAT, __VA_ARGS__)
#define FE1_3(WHAT, X, ...) \
    WHAT(X);                \
    FE1_2(WHAT, __VA_ARGS__)
#define FE1_4(WHAT, X, ...) \
    WHAT(X);                \
    FE1_3(WHAT, __VA_ARGS__)
#define FE1_5(WHAT, X, ...) \
    WHAT(X);                \
    FE1_4(WHAT, __VA_ARGS__)
#define FE1_6(WHAT, X, ...) \
    WHAT(X);                \
    FE1_5(WHAT, __VA_ARGS__)
#define FE1_7(WHAT, X, ...) \
    WHAT(X);                \
    FE1_6(WHAT, __VA_ARGS__)
#define FE1_8(WHAT, X, ...) \
    WHAT(X);                \
    FE1_7(WHAT, __VA_ARGS__)
#define FE1_9(WHAT, X, ...) \
    WHAT(X);                \
    FE1_8(WHAT, __VA_ARGS__)
#define FE1_A(WHAT, X, ...) \
    WHAT(X);                \
    FE1_9(WHAT, __VA_ARGS__)
#define n内部位置(x, _1, _2, _3, _4, _5, _6, _7, _8, _9,_10,N, ...) N
#define h函数分解(函数名, ...) \
    n内部位置(, ##__VA_ARGS__, FE1_A, FE1_9, FE1_8, FE1_7, FE1_6, FE1_5, FE1_4, FE1_3, FE1_2, FE1_1)(函数名, ##__VA_ARGS__)

#define h宏取长度(...) \
    PP_NARG_(__VA_ARGS__, PP_RSEQ_N())

#define PP_NARG_(...) \
    PP_ARG_N(__VA_ARGS__)

#define PP_ARG_N(                                     \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,          \
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
    _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
    _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
    _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
    _61, _62, _63, N, ...) N

#define PP_RSEQ_N()                             \
    63, 62, 61, 60,                             \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define h宏_可重载 __attribute__((overloadable))
#define h宏_构造器 __attribute__((constructor))
#define h宏_析构器 __attribute__((destructor))
#define h宏_起别名(name) __attribute__(objc_runtime_name(name))
#define h宏_中断 __attribute__((interrupt("IRQ")))

#define 输出链(A...)    h函数分解(输出,A)

#define 检查(x)                                                              \
    do                                                                       \
    {                                                                        \
        if ((!(x)))                                                          \
        {                                                                    \
            输出链("err:(", __FILE__,":", __LINE__,"):",#x,"\n")  ;       \
        }                                                                    \
    } while (0)

#define 一页大小 4096
#define 多项选择(索引值, 待选择项数据, ...) \
    ({auto c__[] = {待选择项数据,##__VA_ARGS__};\
        c__[索引值]; })

#define 死循环(A...) ({输出链(A);while(1){}})

#define 基地址 (16*1024*1024)
#define 对齐4k(i) ({int a=(i)+4095;a-(a&4095);})

#ifndef _j基础类型_h_
#define _j基础类型_h_

typedef unsigned char uchar;
    typedef unsigned int  uint;
    struct
    {
        void (*输出整数)(int);
        void (*输出字符)(char);
        void (*输出字符串)(char *);
        void (*输出十六位)(int);
        void (*输出十六位指针)(int *a, int 长);

    } 屏幕;
    void 物理内存_初始化();
    extern char *字符集;

    __attribute__((overloadable)) void 输出(int a);
    __attribute__((overloadable)) void 输出(uint a);
    __attribute__((overloadable)) void 输出(char a);
    __attribute__((overloadable)) void 输出(uchar a);
    __attribute__((overloadable)) void 输出(char *a);

    __attribute__((overloadable)) void 输出十六位(int a);
    __attribute__((overloadable)) void 输出十六位(int *a, int 长);

    void 第一屏_初始化();
    //申请时已经被占用了
    struct
    {
        void *(*申请一页)();
        void *(*申请)(uint 大小);
        void (*删除)(uint *起点, uint 大小);
        void (*删除一页)(uint *位置);
        void (*占用一页)(uint *位置);
        int (*页是否占用)(uint *位置);
        void (*输出剩余空间)();
    } 内存;
#endif

