#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int m, n;
	int maxdiv = 0;//最大公约数
	int minmul = 0;//最小公倍数
	int i;
	int max, min;

	printf("输入两个数，求它们的最大公约数maxdiv,和最小公倍数minmul:");
	scanf("%d%d", &m, &n);

	max = (m > n) ? m : n;
	min = (m > n) ? n : m;

	i = min - 1;
	while (max % i || min % i)	i--;//最大公约数
	maxdiv = i;

	i = max + 1;
	while (i % max || i % min)  i++;//最小公倍数
	minmul = i;

	printf("maxdiv = %d, minmul = %d\n", maxdiv, minmul);

	return 0;
}