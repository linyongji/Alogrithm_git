#include<stdio.h>
#include "../include/13_MyAtoi.h"
#include "../include/14_SingleNumber.h"
int main()
{
	int arr[] = { -1,-2,-3,-4,-4,-3,-2,-1,0 };
	printf("%d\n", SingleNumber(arr, sizeof(arr)/sizeof(int)));
	return 0;
}
