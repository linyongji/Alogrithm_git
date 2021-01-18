#include"../include/9_AddBinary.h"

char* AddBinary(char* a, char* b)
{
	int len_a = strlen(a) - 1;//����ַ���a�ĳ���
	int len_b = strlen(b) - 1;//����ַ���b�ĳ���
	int carry = 0;//��λ��־
	int len = len_a > len_b ? len_a : len_b;//��ȡ�����ַ����г��Ƚϳ�����һ��

	char* pstr = (char*)malloc(sizeof(char) * (len + 3));//����һ��ָ����Ϊ����ֵ������������ռ���Ϊ�˷�ֹ�н�λ���ַ���β��־\0
	if (NULL == pstr)
		return NULL;
	pstr[len + 2] = '\0';//���ַ���ĩβ��\0
	len = len + 1;
	while ((len_a >= 0) || (len_b >= 0)) {//ֻҪ�����ַ�����һ��û�����꣬���������������������ַ�����ĩβ��ʼ����
		int sum = carry;//sum��������a[len_a]��b[len_b]��carry��ӵĽ����sum����Ϊ��0,1,2,3
		sum += (len_a >= 0 ? a[len_a] - '0' : 0);
		sum += (len_b >= 0 ? b[len_b] - '0' : 0);
		carry = sum / 2;//��sum=2��3ʱ��Ҫ��λ��2��ʾ��a[a_len]��b[b_len]���Ҫ��λ��3��ʾ����һλ��Ҫ��λ
		pstr[len] = '0' + sum % 2;//��pstr[len]��ֵ��
		len_a--, len_b--, len--;
	}
	//�ж�Ҫ��Ҫ��ǰ��0
	if (carry == 0) {
		return (pstr + 1);//ָ���һ����ʾָ������ƶ����������������λ�Ļ�ָ���ָ���0����һλ��
	}
	else {
		pstr[0] = '1';
		return pstr;
	}
	//free(pstr);
}