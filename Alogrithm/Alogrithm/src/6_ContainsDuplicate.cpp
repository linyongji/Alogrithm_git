#include"../include/6_ContainsDuplicate.h"

int cmp_6(const void* _a, const void* _b) {
	int a = *(int*)_a, b = *(int*)_b;
	return a - b;
}
//6.���򣬱Ƚ�����Ԫ���Ƿ���ȣ�������򷵻�true�����򷵻�false��
bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp_6);
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] == nums[i + 1]) {
			return true;
		}
	}
	return false;
}