#pragma warning(disable:4996)
#include <stdio.h>

void swap(char* c1, char* c2, int width)
{
	char temp = 0;
	int i = 0;
	//按字符大小逐个交换
	for (i = 0; i < width; i++)
	{
		temp = *c1;
		*c1 = *c2;
		*c2 = temp;
		c1++;
		c2++;
	}
	
}
void my_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i, j;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if(cmp > 0)
			{
				//传参两个元素的地址和字节大小
				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	my_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);


	return 0;
}