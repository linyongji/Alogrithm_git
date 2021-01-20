#include"../include/6_ContainsDuplicate.h"
//题目：给定一个整数数组，判断是否存在重复元素。如果任意一值在数组中出现至少两次，函数返回true 。
//		如果数组中每个元素都不相同，则返回false 。
//思路：先排序，然后比较相邻元素是否相等，若相等则返回true，否则返回false。
//qsort比较函数，返回值小于0，升序；返回值大于0，降序
int cmp_6(const void* _a, const void* _b) {
	int a = *(int*)_a, b = *(int*)_b;
	return a - b;
}

bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp_6);//对传进来的数组排序
	for (int i = 0; i < numsSize - 1; i++) {//遍历数组，
		if (nums[i] == nums[i + 1]) {//对相邻的两个元素作比较，如果相等返回true；
			return true;
		}
	}
	return false;//不相等，返回false
}