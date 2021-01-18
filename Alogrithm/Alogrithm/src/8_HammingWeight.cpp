#include"../include/8_HammingWeight.h"
//8.定义一个count，记录1的个数，把入参和1与操作，如果为1，count加1；如果为0，count加0
//把入参右移一位，循环上面的操作，直到n=0时结束。
int HammingWeight(uint32_t n)
{
	int n_Count = 0;
	while (n) {
		n_Count += n & 1;
		n >>= 1;
	}
	return n_Count;
}