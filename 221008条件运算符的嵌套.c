//���������������Ƕ������ɴ��⣺ѧϰ�ɼ� >= 90�ֵ�ͬѧ��A��ʾ��60 - 89��֮�����B��ʾ��60�����µ���C��ʾ��
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