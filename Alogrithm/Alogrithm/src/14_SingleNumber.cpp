#include "../include/14_SingleNumber.h"

//��Ŀ������һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˼·��ʹ������������ʣ�
//	1.0����κ������κ���
//	2.�κ�������Լ������Լ���0
//	3.�����Ͻ���ɺͽ�����
int SingleNumber(int* nums, int numsSize)
{
	for (int i = 1; i < numsSize; i++) {// i��1��ʼ��nums[0]��nums[1]��򣬽��������nums[0]��
		nums[0] = nums[0] ^ nums[i];//nums[0]���κͺ���������,���������nums[0]�У�
	}
	return nums[0];//���������������Ժ󣬷���ֵ���ǵ������ڵ�����
}