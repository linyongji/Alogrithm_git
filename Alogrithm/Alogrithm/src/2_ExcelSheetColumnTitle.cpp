#include "../include/2_ExcelSheetColumnTitle.h"

//����һ���������������� Excel �������Ӧ�������ƣ������Excel�����Ҳ������У��򷵻�""��
char* ExcelSheetColumnTitle(int n)
{
	char* ret = (char*)malloc(sizeof(char) * 10);//����һƬ�ռ䣬����Ҫ���ص��ַ���
	int i = 9;//
	while (n)
	{
		n -= 1;//��n��һ����Ϊn�����Ǵ�'A'��ʼ��
		ret[i - 1] = n % 26 + 'A';//�Ӻ���ǰ��ֵ�������һ����ֵ����һ��
		n /= 26;
		i--;//����һ����ֵ
	}
	ret[9] = '\0';
	return ret + i;//ȥ��ǰ���ǰ���ַ������ǰ��û���ַ���ָ�����
}