#include<stdio.h>
#include "../include/23_RestoreIpAddresses.h"

int main()
{
	char str[] = "11112345";
	int m = 0;
	char** res;
	res = RestoreIpAddresses(str, &m);
	for (int i = 0; i < m; i++)
		printf("%s\n", res[i]);
	
}
