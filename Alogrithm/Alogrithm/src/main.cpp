#include<stdio.h>
#include "../include/13_MyAtoi.h"
int main()
{
	char s[] = "2147483648";
	printf("%d\n", MyAtoi(s));
	//printf("%d\n", 2147483647+ 2147483649);
	return 0;
}
