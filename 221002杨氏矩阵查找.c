#pragma warning(disable:4996)
#include <stdio.h>

int Find_Num(int arr[3][3], int num, int* px, int* py)
{
	int x = 0;
	int y = *py - 1;
	
	while(x <= 2 && y >= 0)
	{
		if (arr[x][y] < num)
		{
			x++;
		}
		else if (arr[x][y] > num)
		{
			y--;
		}
		else
		{
			//找到了，返回坐标
			*px = x;
			*py = y;
			return 1;
		}
	}
	//找不到
	return 0;
}
int main()
{
	int arr[3][3] = {{1,2,3} ,{4,5,6} ,{7,8,9}};
	int num = 8;
	int x = 3;
	int y = 3;
	int ret = -1;

	ret = Find_Num(arr, num, &x, &y);

	if (ret == 1)
	{
		printf("找到了，下标是%d,%d\n", x, y);
	}
	else if (ret == 0)
	{
		printf("找不到\n");
	}

	return 0;
}