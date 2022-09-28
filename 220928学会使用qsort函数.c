#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
#include <string.h>

struct Stu
{
	char name[11];
	int age;
};

int cmp_int(const void* e1, const void* e2)
{
	//void*Ҫ�����ã�������ǿ������ת����int��ָ��
	//��e1>e2�򷵻�>0����...
	return *(int*)e1 - *(int*)e2;
}

int cmp_char(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}

int cmp_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}

int cmp_struct(const void* e1, const void* e2)
{
	// -> ��ָ�������������Ҫ��*������
	return (((struct Stu*)e1)->age) - (((struct Stu*)e2)->age);
}

int cmp_struct_by_name(const void* e1, const void* e2)
{
	return strcmp((*(struct Stu*)e1).name, ((*(struct Stu*)e2).name));
}

int main()
{
	int arr1[] = { 9,8,7,6,5,4,3,2,1 };
	char arr2[] = {'f','g','d','c','b','a'};
	float arr3[] = { 2.0,5.0,6.0,7.0,4.0,9.0 };
	struct Stu s1[] = {{"����",19},{"����",20},{"����",18}};

	//  ��������
	//	void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
	//	����
	//	base-- ָ��Ҫ���������ĵ�һ��Ԫ�ص�ָ�롣
	//	nitems-- �� base ָ���������Ԫ�صĸ�����
	//	size-- ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
	//	compar-- �����Ƚ�����Ԫ�صĺ�����������ָ�루�ص�����
	qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), cmp_int);

	qsort(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), cmp_char);

	qsort(arr3, sizeof(arr3) / sizeof(arr3[0]), sizeof(arr3[0]), cmp_float);

	//qsort(s1, sizeof(s1) / sizeof(s1[0]), sizeof(s1[0]), cmp_struct);

	qsort(s1, sizeof(s1) / sizeof(s1[0]), sizeof(s1[0]), cmp_struct_by_name);
	return 0;
}