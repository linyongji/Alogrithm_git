#include "../include/14_SingleNumber.h"

//题目：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//思路：使用异或，异或的性质：
//	1.0异或任何数＝任何数
//	2.任何数异或自己＝把自己置0
//	3.异或符合结合律和交换律
int SingleNumber(int* nums, int numsSize)
{
	for (int i = 1; i < numsSize; i++) {// i从1开始，nums[0]和nums[1]异或，结果保存在nums[0]中
		nums[0] = nums[0] ^ nums[i];//nums[0]依次和后面的数异或,结果保存在nums[0]中，
	}
	return nums[0];//所有数都运算完以后，返回值就是单独存在的数。
}