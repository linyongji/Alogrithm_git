
#include "../include/3_bool IsUgly.h "  
//�ж�һ�����Ƿ�Ϊ�������ܱ�2 3 5�������������ܷ���true�����ܷ���false
//˼·�������ѭ���ж�%2��%3��%5�Ƿ�Ϊ0���������Ӧ��������������ѭ������num�жϣ�
//Ϊ1����˵���ܱ�2��3��5�������ǳ����������ǡ�
bool IsUgly(int num)
{	//����жϣ����С�ڵ���0ֱ�ӷ���false
	if (num <= 0) {
		return false;
	}
	while (1) {//��numѭ���жϲ�����Ӧ�����㣬ֱ�������������������˳�ѭ��
		if (num % 2 == 0) {
			num = num / 2;
		}
		else if (num % 3 == 0) {
			num = num / 3;
		}
		else if (num % 5 == 0) {
			num = num / 5;
		}
		else {
			break;
		}
	}
	if (num == 1) {//������num�жϣ����Ϊ1��˵���ܱ��������ǳ����������ǳ�������false
		return true;
	}
	return false;
}