#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int is_rotate(char arr1[], char arr2[])
{
	unsigned int len1 = strlen(arr1);
	unsigned int len2 = strlen(arr2);

	//自己追加自己	"abcdefabcdef"
	strncat(arr1, arr1, len1);

	//长度相等再判断
	if (len1 != len2)
		return 0;

	//
	if (strstr(arr1, arr2) != NULL)
		return 1;
	else
		return 0;
}
int main()
{
	char ch1[33] = "abcdef";
	char ch2[] = "cdefab";
	int ret = 0;
	ret = is_rotate(ch1, ch2);

	if (ret == 1)
		printf("Yes");
	else
		printf("No");

	return 0;
}