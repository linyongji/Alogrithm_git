#include "../include/4_IsPalindrome.h"

//˼·���Դ�����������֪���Ǽ�λ������ѭ��%10����/10,ȡ��ÿλ�ϵ����֣�������*10��ӣ��õ���ת�����
//����ٺ�ԭ�����Աȡ�

bool IsPalindrome(int x)
{
	int x_Count = 1;//����һ��count����ͳ�ƴ����������Ǽ�λ��
	long long x_Coln1 = x;//�Ѵ�������������һ�ݣ�������õ�
	long long x_Turn = 0;//�������淭ת���ֵ������int��ת���������
	while ((x / 10) != 0) {//ͨ��ѭ�����������Ǽ�λ��
		x_Count++;
		x = x / 10;
	}
	x = x_Coln1;//����ԭ�������滹Ҫ�õ�
	for (int i = 0; i < x_Count; i++) {//�����ú������ŵ�x_Turn�У��������������
		int temp = x % 10;
		x_Turn = x_Turn * 10 + temp;
		x = x / 10;
	}
	if (x_Coln1 < 0) {//�ж�����Ƿ�Ϊ�������ǵĻ����ϸ��ţ��������ñ�
		x_Turn = 0 - x_Turn;
	}
	if (x_Turn == x_Coln1) {//�жϷ�ת�������ԭ���Ƿ����
		return true;
	}
	return false;
}