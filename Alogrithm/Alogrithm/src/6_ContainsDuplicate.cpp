#include"../include/6_ContainsDuplicate.h"
//��Ŀ������һ���������飬�ж��Ƿ�����ظ�Ԫ�ء��������һֵ�������г����������Σ���������true ��
//		���������ÿ��Ԫ�ض�����ͬ���򷵻�false ��
//˼·��������Ȼ��Ƚ�����Ԫ���Ƿ���ȣ�������򷵻�true�����򷵻�false��
//qsort�ȽϺ���������ֵС��0�����򣻷���ֵ����0������
int cmp_6(const void* _a, const void* _b) {
	int a = *(int*)_a, b = *(int*)_b;
	return a - b;
}

bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp_6);//�Դ���������������
	for (int i = 0; i < numsSize - 1; i++) {//�������飬
		if (nums[i] == nums[i + 1]) {//�����ڵ�����Ԫ�����Ƚϣ������ȷ���true��
			return true;
		}
	}
	return false;//����ȣ�����false
}