//分解质因数
//就是
//一个数 = 质数*质数*....
//质数从2开始按从小到大排列
//比如，84除2可以被除尽得42，
//42除2可被除尽得21
//21除3得7
//7是质数
//最后得：84 = 2*2*3*7

#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i;
	int temp;
	int input = 0;
	printf("输入一个数，别问为什么：");
	scanf("%d", &input);
	temp = input;
	printf("%d = ", input);

	for (i = 2; i < input; i++)
	{
		while(temp % i == 0)
		{
			printf("%d * ", i);
			temp /= i;
		}
	}
	printf("\b\b");

	return 0;
}