#include "../include/2_ExcelSheetColumnTitle.h"

//给定一个整数，返回它在 Excel 表中相对应的列名称，如果在Excel表中找不到该列，则返回""。
char* ExcelSheetColumnTitle(int n)
{	//int类型大于0的数为0~2147483647，可以用7个A~Z的字母表示，int不会超过26的7次方
	char* ret = (char*)malloc(sizeof(char) * 8);//所以这里申请8字节的空间，一个字节存放\0标志
	int i = 7;//用来访问i字符串中的每个字符
	ret[7] = '\0';//给结尾赋上\0标志位
	while (n)//当n等于0时结束
	{
		n -= 1;//给n减一，因为n后面是从字符'A'开始的相加的
		ret[i-1] = n % 26 + 'A';//从后往前赋值，从最后一个赋值到第一个
		n /= 26;
		i--;//给下一个字符赋值
	}
	return ret + i;//去掉前面的前导字符，如果前面没有字符则指针后移
}