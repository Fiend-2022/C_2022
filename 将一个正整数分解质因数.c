//�ֽ�������
//����
//һ���� = ����*����*....
//������2��ʼ����С��������
//���磬84��2���Ա�������42��
//42��2�ɱ�������21
//21��3��7
//7������
//���ã�84 = 2*2*3*7

#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i;
	int temp;
	int input = 0;
	printf("����һ����������Ϊʲô��");
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