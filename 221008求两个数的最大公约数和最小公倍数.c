#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int m, n;
	int maxdiv = 0;//���Լ��
	int minmul = 0;//��С������
	int i;
	int max, min;

	printf("�����������������ǵ����Լ��maxdiv,����С������minmul:");
	scanf("%d%d", &m, &n);

	max = (m > n) ? m : n;
	min = (m > n) ? n : m;

	i = min - 1;
	while (max % i || min % i)	i--;//���Լ��
	maxdiv = i;

	i = max + 1;
	while (i % max || i % min)  i++;//��С������
	minmul = i;

	printf("maxdiv = %d, minmul = %d\n", maxdiv, minmul);

	return 0;
}