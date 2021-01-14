#include "../include/2_ExcelSheetColumnTitle.h"
#define STR_LEN 100
//给定一个整数，返回它在 Excel 表中相对应的列名称，如果在Excel表中找不到该列，则返回""。
char* ExcelSheetColumnTitle(int n)
{
	static char str[STR_LEN] = { 0 };
	int i = 0;
	while (n > 0) {
		 if ((n > 0) && (n <= 26)) {
			str[i] = 'A' + n - 1;
		}
		else if (n > 26) {
			 str[i] = 'A';
		}
		 n = n - 26;
		 i++;	
	}
	char* pstr = str;
	return pstr;
}