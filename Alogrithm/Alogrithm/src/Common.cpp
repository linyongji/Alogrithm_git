#include "../include/Common.h"

char* GetAuthor() {
	char* Author = (char*)malloc(sizeof(char)*10);
	Author = "Author:������";
	return Author;
}
char* GetLanguage() {
	static char Language[] = "Language:C����";
	return Language;
}