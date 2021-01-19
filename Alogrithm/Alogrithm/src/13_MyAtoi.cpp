#include "../include/13_MyAtoi.h"

int MyAtoi(char* s) {
	int Index = 0;//用来遍历字符串s，作为下标使用
	int flag = 1;//符号标志位，>0则读到正号，<0则读到负号
	int ret = 0;//用来存放运算的结果，防止溢出
	while (s[Index] == ' ') {//丢弃无用的开头空格字符
		Index++;
	}
	if (s[Index] == '-') {//读取负号，flag改变
		flag = -1;
		Index++;
	}
	else if (s[Index] == '+') {//读取正号，flag改变
		flag = 1;
		Index++;
	}
	else if (s[Index] < '0' || s[Index] > '9') {//如果该字符串中的第一个非空格字符不是一个有效整数字符、
		return 0;					//字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换,直接返回0
	}
	while ('0' <= s[Index] && s[Index] <= '9') {//遍历0~9的字符，直到遍历完为止
		ret = ret * 10 + int(s[Index] - '0');//把遍历到的结果转成整数
		if (ret*10/10 != ret && flag > 0) {//给ret先乘10，再除10，判断是否与原数相等
			return INT_MAX;					//如果不相等说明溢出，再判断是不是正溢出，返回INT_MAX
		}
		else if (ret * 10 / 10 != ret && flag < 0) {//如果是负溢出，返回INT_MIN
			return INT_MIN;
		}
		Index++;
	}
	if (flag < 0) {//如果while走完后没有返回值，说明没有溢出，返回相应的值
		return 0 - ret;
	}
	return ret;
}