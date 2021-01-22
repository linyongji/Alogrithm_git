#include "../include/16_ReverseBits.h"
//题目:颠倒给定的 32 位无符号整数的二进制位。
//思路：把入参n和1相与，取到最后一位，res左移一位，再把最后一位和res进行或操作并赋值给res
//		循环上面的操作32次，返回res，res就是颠倒后的结果、
uint32_t ReverseBits(uint32_t n) {
	uint32_t res = 0;		//定义一个uint32_t类型数，作为返回值
	for (int i = 0; i < 32; i++) {//循环位运算32次
		res = res << 1;		//res左移一位，准备给最后一位赋值，
		res = res | (n & 1);//取n的最后一位，并把最后一位保存到res中，
		n = n >> 1;//n循环右移
	}
return res;
}