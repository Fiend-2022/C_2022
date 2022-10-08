//利用条件运算符的嵌套来完成此题：学习成绩 >= 90分的同学用A表示，60 - 89分之间的用B表示，60分以下的用C表示。
#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int input = 0;
	char c;
	scanf("%d", &input);
	c = (input >= 90) ? 'A' : (input >= 60) ? 'B' : 'C';
	printf("input = %c\n", c);
	return 0;
}