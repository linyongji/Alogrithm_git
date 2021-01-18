#include"../include/8_HammingWeight.h"
//8.����һ��count����¼1�ĸ���������κ�1����������Ϊ1��count��1�����Ϊ0��count��0
//���������һλ��ѭ������Ĳ�����ֱ��n=0ʱ������
int HammingWeight(uint32_t n)
{
	int n_Count = 0;
	while (n) {
		n_Count += n & 1;
		n >>= 1;
	}
	return n_Count;
}