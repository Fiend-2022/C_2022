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
	//void*要解引用，必须先强制类型转换成int型指针
	//若e1>e2则返回>0的数...
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
	// -> 是指针操作符，不需要加*解引用
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
	struct Stu s1[] = {{"张三",19},{"李四",20},{"王五",18}};

	//  函数声明
	//	void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
	//	参数
	//	base-- 指向要排序的数组的第一个元素的指针。
	//	nitems-- 由 base 指向的数组中元素的个数。
	//	size-- 数组中每个元素的大小，以字节为单位。
	//	compar-- 用来比较两个元素的函数，即函数指针（回调函数
	qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), cmp_int);

	qsort(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), cmp_char);

	qsort(arr3, sizeof(arr3) / sizeof(arr3[0]), sizeof(arr3[0]), cmp_float);

	//qsort(s1, sizeof(s1) / sizeof(s1[0]), sizeof(s1[0]), cmp_struct);

	qsort(s1, sizeof(s1) / sizeof(s1[0]), sizeof(s1[0]), cmp_struct_by_name);
	return 0;
}