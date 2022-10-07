#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#include <string.h>

void my_qsort(void *p, int num, int s, int (*cmp)(const void *, const void *));
struct STU
{
    char name[11];
    int age;
    float score;
};

//排序char类型的函数
int sort_char(const void *e1, const void *e2)
{
    return (int)(*(char *)e1 - *(char *)e2);
}

//排序int类型的函数
int sort_int(const void *e1, const void *e2)
{
    return *(int *)e1 - *(int *)e2;
}

//排序float类型的函数
int sort_float(const void *e1, const void *e2)
{
    if((*(float *)e1 - *(float *)e2) > 0)   return 1;
    if((*(float *)e1 - *(float *)e2) == 0)   return 0;
    if((*(float *)e1 - *(float *)e2) < 0)   return -1;
}

//
int sort_STU_byname(const void *e1, const void *e2)
{
    return strcmp((((struct STU *)e1))->name, ((struct STU *)e2)->name);
}
int main()
{
    char arrc[] = {'f', 'e', 'd', 'u', 'o', 'h', 'a'};
    int arri[] = {4, 8, 6, 1, 3, 9, 5, 7};
    float arrf[] = {0.32, 0.21, 0.55, 0.91, 0.66, 0.11, 0.32};
    struct STU s[] = {{"李四", 18, 112},{"张三", 17, 141}, {"王五", 19, 133}};

    //最后一个参数sort_char是一个函数指针，返回类型为int型
    // qsort(arrc, sizeof(arrc) / sizeof(arrc[0]), sizeof(arrc[0]), sort_char);
    // qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(arri[0]), sort_int);
    // qsort(arrf, sizeof(arrf) / sizeof(arrf[0]), sizeof(arrf[0]), sort_float);
    // qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), sort_STU_byname);

    my_qsort(arrc, sizeof(arrc) / sizeof(arrc[0]), sizeof(arrc[0]), sort_char);
    my_qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(arri[0]), sort_int);
    //浮点型又调试了一个小时，结果又是语法错误，TMD小于1的浮点强转成int就成0了
    my_qsort(arrf, sizeof(arrf) / sizeof(arrf[0]), sizeof(arrf[0]), sort_float);
    my_qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), sort_STU_byname);
    
    int i ;
    for(i = 0; i<3; i++)    printf("%s\n",s[i].name);

    return 0;
}

//实现自己的qsort函数—————————————————————————————————————————————————————————————————————————
void swap(char *c1, char *c2, int width)
{
    char tmp;
    int i;
    for (i = 0; i < width; i++)
    {
        tmp = *c1;
        *c1 = *c2;
        *c2 = tmp;
        c1++;
        c2++;
    }
}

void my_qsort(void *p, int sz, int width, int (*cmp)(const void *e1, const void *e2))
{
    int i, j;
    for (i = 0; i < sz - 1; i++)
    {
        for (j = 0; j < sz - 1 - i; j++)
        {
            // if(cmp > 0) 第一次实现的时候写成这样，不知道怎么想的，回调函数，回调了个寂寞
            if (cmp((char *)p + j * width, (char *)p + (j + 1) * width) > 0)
            {
                //交换两个数：char型基地址＋字节宽度
                swap((char *)p + j * width, (char *)p + (j + 1) * width, width);
            }
        }
    }
}
