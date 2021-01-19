#include "../include/13_MyAtoi.h"

int MyAtoi(char* s) {
	int Index = 0;//���������ַ���s����Ϊ�±�ʹ��
	int flag = 1;//���ű�־λ��>0��������ţ�<0���������
	int ret = 0;//�����������Ľ������ֹ���
	while (s[Index] == ' ') {//�������õĿ�ͷ�ո��ַ�
		Index++;
	}
	if (s[Index] == '-') {//��ȡ���ţ�flag�ı�
		flag = -1;
		Index++;
	}
	else if (s[Index] == '+') {//��ȡ���ţ�flag�ı�
		flag = 1;
		Index++;
	}
	else if (s[Index] < '0' || s[Index] > '9') {//������ַ����еĵ�һ���ǿո��ַ�����һ����Ч�����ַ���
		return 0;					//�ַ���Ϊ�ջ��ַ����������հ��ַ�ʱ������ĺ�������Ҫ����ת��,ֱ�ӷ���0
	}
	while ('0' <= s[Index] && s[Index] <= '9') {//����0~9���ַ���ֱ��������Ϊֹ
		ret = ret * 10 + int(s[Index] - '0');//�ѱ������Ľ��ת������
		if (ret*10/10 != ret && flag > 0) {//��ret�ȳ�10���ٳ�10���ж��Ƿ���ԭ�����
			return INT_MAX;					//��������˵����������ж��ǲ��������������INT_MAX
		}
		else if (ret * 10 / 10 != ret && flag < 0) {//����Ǹ����������INT_MIN
			return INT_MIN;
		}
		Index++;
	}
	if (flag < 0) {//���while�����û�з���ֵ��˵��û�������������Ӧ��ֵ
		return 0 - ret;
	}
	return ret;
}