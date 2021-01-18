#include "../include/2_ExcelSheetColumnTitle.h"

//给定一个整数，返回它在 Excel 表中相对应的列名称，如果在Excel表中找不到该列，则返回""。
char* ExcelSheetColumnTitle(int n)
{
	char* ret = (char*)malloc(sizeof(char) * 10);//开辟一片空间，存需要返回的字符串
	int i = 9;//
	while (n)
	{
		n -= 1;//给n减一，因为n后面是从'A'开始的
		ret[i - 1] = n % 26 + 'A';//从后往前赋值，从最后一个赋值到第一个
		n /= 26;
		i--;//给下一个赋值
	}
	ret[9] = '\0';
	return ret + i;//去掉前面的前导字符，如果前面没有字符则指针后移
}