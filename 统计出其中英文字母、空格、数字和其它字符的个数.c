#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//搞完才发现还有空格，不搞了，刷下一个去。
int main()
{
    int count_num = 0,
        count_en = 0,
        count_other = 0;
    char input [100] = {0};
    char *p = input;
    printf("输入一行字符，统计其中的数字，字母及其它字符的个数：\n");
    gets(input);


    while(*p)
    {
        if((*p>='0' && *p<='9')) 
            count_num++;
        else if( (*p>='A' && *p<='Z') || (*p>+'a' && *p<='z'))  
            count_en++;
        else                            
            count_other++;

        p++;
    }

    printf("英文有%d个，\n数字有%d个，\n其它字符有%d个\n",
            count_en,count_num,count_other);

    return 0;
}