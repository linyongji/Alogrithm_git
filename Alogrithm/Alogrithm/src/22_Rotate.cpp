#include "../include/22_Rotate.h"
//��Ŀ������һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����k�ǷǸ�����

//����һ������һ���µ����飬��ÿ��Ԫ�ذ�����Ҫ�ƶ���λ�ã����ηŵ���ŵ��µ������С�
void Rotate1(int* nums, int numsSize, int k) {
	int* cpynums=(int *)malloc(sizeof(int) * numsSize);	//�����µ�����
	for (int i = 0; i < numsSize; i++) {				//i��0��ʼ����i��numsSize���ʱ����
		cpynums[(i+k)%numsSize] = nums[i];				//��nums����ĵ�һ���������һ�������ηŵ�������ĵ�i+k��λ��
	}
	for (int i = 0; i < numsSize; i++) {				//���ƶ���ɵ����鿽����ԭ����
		nums[i] = cpynums[i];
	}
}

//������ʹ�õ����������ú���������������������ָ������Ԫ��
void reverse(int* nums, int start, int end) {
	int temp = 0;
	while (start < end) {
		temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}
//���������Ȱ������������ã��ٰ�0��k-1���ã��ٰ�k��numsSize-1���ã��õ���ת�������
void Rotate2(int* nums, int numsSize, int k) {
	k = k % numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k ,numsSize - 1);
	for (int i = 0; i < numsSize; i++) {				//���ƶ���ɵ����鿽����ԭ����
		printf("%d ", nums[i]);
	}
}

//����������װ�滻��
//1,ֱ�ӱ������飬����ǰλ�õ�ֵ�滻�����滻��λ�ã����滻λ�õ�ֵ�����ڱ���change�У�������һ���滻
//2,������� numsSize ������ k �ı���ʱ���ͻ����ѭ��������ͬλ�õ�����
//3,���ÿ������ѭ��֮����Ҫ��1��������һ��λ�õ��ƶ�

void Rotate3(int* nums, int numsSize, int k) {
	int count = 0;								//�����������Ԫ�صĴ��������ΪnumsSize��
	for (int i = 0; count < numsSize; i++) {	//i�����ã���numsSizeΪk�ı�����ѭ��������ͬλ������ʱ���Ѵ�����������ƶ�����һλ��
		int temp = 0;							//��ʱ��������������ʱ��
		int change = nums[i];					//��ŵ�һ����Ҫ�滻��ֵ
		do
		{
			count++;							//countʵ�ʴ�1��ʼ��
			temp = change;						//������ǰλ�õ�ֵ��Ҫ���滻λ�õ�ֵ�����滻λ�õ�ֵ����������change�У�׼����һ���滻
			change = nums[(k * count + i) % numsSize];
			nums[(k * count + i) % numsSize] = temp;
			if ((count * k)%numsSize == 0)		//��numsSize ������ k �ı���ʱ������ѭ����
				break;
		} while (count != numsSize);			//���count��numsSize��ȣ�˵���ý�����
	}
}