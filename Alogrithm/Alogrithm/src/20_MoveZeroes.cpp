#include "../include/20_MoveZeroes.h"
//��Ŀ������һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//˼·��������������left��right����ʼʱ��ָ�������ͷ��
//		right�������������ÿһ��Ԫ�أ�leftָ�������ͷ��β�ĵ�һ��0
//		���nums[right]��Ϊ0���򽻻�������right��left������ƶ�
//		���nums[right]Ϊ0����leftָ����0��rightָ����һ����
void MoveZeroes(int* nums, int numsSize) {
	int left = 0, right = 0, temp = 0;
	while (right < numsSize) {		//��right�����鳤�����ʱ�˳�
		if (nums[right] != 0) {		//�ж�Ԫ���Ƿ�Ϊ0�������򽻻�������ָ��ͬʱ�ƶ���Ϊ0��ֻ��right�ƶ���leftָ����0
			temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
		}
		right++;
	}

}