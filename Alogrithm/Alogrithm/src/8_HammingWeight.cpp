#include"../include/8_HammingWeight.h"
//题目：编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为‘1’的个数（也被称为汉明重量）。
//思路：定义一个count，记录1的个数，把入参和1与操作，如果为1，count加1；如果为0，count加0

int HammingWeight(uint32_t n)
{
	int n_Count = 0;
	while (n) {
		n_Count += n & 1;//n & 1的结果为1或者0,1说明最后一位为1,0说明最后一位为0
		n >>= 1;//把入参右移一位，循环上面的操作，直到n=0时结束。
	}
	return n_Count;
}