#include "../include/Common.h"
#include <stdio.h>
int main()
{
	char *Language = GetLanguage();
	char* Author = GetAuthor();
	printf("%*s\n", 40,Author);
	printf("%*s\n", 40,Language);

}
