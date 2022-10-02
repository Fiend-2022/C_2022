#pragma warning(disable:4996)
#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cp = (char*)p1;

	while (s1)
	{
		s1 = cp;
		s2 = (char*)p2;

		// ---> (*s1 != '\0') <---  可以写成 (!*s1) <此事再议>
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))   
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')	// 这里少一个*号，调试了半天，笑cry  - -！
		{
			return cp;
		}
		cp++;
	}
	return NULL;
}

int main()
{
	char a[] = "abbbcdef";
	char b[] = "bbc";
	char* ret = my_strstr(a, b);
	printf("%s", ret);



	return 0;
}