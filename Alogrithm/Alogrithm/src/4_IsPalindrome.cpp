#include "../include/4_IsPalindrome.h"

//思路：对传进来的数先知道是几位数，再循环%10，再/10,取到每位上的数字，再逆序*10相加，得到翻转后的数
//最后再和原数作对比。

bool IsPalindrome(int x)
{
	int x_Count = 1;//定义一个count用来统计传进来的数是几位数
	long long x_Coln1 = x;//把传进来的数拷贝一份，后面会用到
	long long x_Turn = 0;//用来保存翻转后的值，考虑int翻转后溢出问题
	while ((x / 10) != 0) {//通过循环来获得入参是几位数
		x_Count++;
		x = x / 10;
	}
	x = x_Coln1;//保存原数，后面还要用到
	for (int i = 0; i < x_Count; i++) {//把逆置后的数存放到x_Turn中（保存的是正数）
		int temp = x % 10;
		x_Turn = x_Turn * 10 + temp;
		x = x / 10;
	}
	if (x_Coln1 < 0) {//判断入参是否为负数，是的话加上负号，不是则不用变
		x_Turn = 0 - x_Turn;
	}
	if (x_Turn == x_Coln1) {//判断翻转后的数和原数是否相等
		return true;
	}
	return false;
}