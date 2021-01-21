#include<stdio.h>
#include "../include/15_WordPattern.h"


int main()
{
	char p[] = "aba";
	char s[] = "dog cat dog d";
	printf("%d\n", WordPattern(p, s));
	return 0;
}
