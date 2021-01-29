#include "../include/23_RestoreIpAddresses.h"
//��Ŀ������һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ�IP��ַ��ʽ��
//		��Ч��IP��ַ�������ĸ�������ÿ������λ��0��255֮����ɣ�������֮���� '.' �ָ���
//˼·������֪��һ���Ϸ�ip��ַ��Ϊ�ĶΣ�ÿһ�ζ�������������ֱ�Ϊ��һλ������λ������λ����
//		�������Կ���ʹ�õݹ�ķ�����������������Ϊ������֧������Ϊ�����ú������ҷ��ϵ�һ�ε���������
//		��һ����һλ�� ����λ�� ����λ�� ʱ ��ʣ�ַ����ȷ��ϺϷ�ip��ַҪ�������ʹ�ñ��������ҵڶ���
//		ÿ�β��Ҷ����¼���ҵ��˵ڼ��Σ����Ѳ鵽�ĺϷ�ip������ʱ�ַ��������Ķβ���ʱ����ʱ�ַ������������ص��ַ���
//		������ȥ������¼�Ϸ�ip�ĸ���
void dfs(char* s, int s_len, char** returnStr,int *returnSize, int step, int index, char* temp) {
	//��ĳһ��Ϊ1λ��ʱ������ʣ�µ��ַ��ܷ���ɺϷ�ip�������ǣ�����4-step  ��С�� 4-step��3�����������������棺
	if ((s_len - index - 1 >= 4 - step) && (s_len - index - 1 <= (4 - step) * 3)) {
		temp[index + step - 1] = s[index];		//�ѷ��ϵ���1���ַ��ŵ���ʱ�ַ����ĵ�step����
		temp[index + step ] = '.';				//��'.',��һ�ν�����������һ��
		dfs(s, s_len, returnStr, returnSize, step + 1, index + 1, temp);//�����ݹ飬������һ��
	}
	//��ĳһ��Ϊ2λ��ʱ������ʣ�µ��ַ��ܷ���ɺϷ�ip�������ǣ�����4-step  ��С�� 4-step��3 �Ҳ�Ϊ0��ͷ�����������������棺
	if ((s_len - index - 2 >= 4 - step) && (s_len - index - 2 <= (4 - step) * 3) && s[index] != '0') {
		temp[index + step - 1] = s[index];		//�ѷ��ϵ���2���ַ��ŵ���ʱ�ַ����ĵ�step����
		temp[index + step] = s[index+1];		
		temp[index + step + 1] = '.';			//��'.',��һ�ν�����������һ��
		dfs(s, s_len, returnStr, returnSize, step + 1, index + 2, temp);//�����ݹ飬������һ��
	}
	//��ĳһ��Ϊ3λ��ʱ������ʣ�µ��ַ��ܷ���ɺϷ�ip�������ǣ�����4-step  �� С�� 4-step��3 �� ��Ϊ0��ͷ �� �����ַ���ɵ�
	//���ֲ��ܴ���255�����������������棺
	if ((s_len - index - 3 >= 4 - step) && (s_len - index - 3 <= (4 - step) * 3) && s[index] != '0' && (s[index] - '0') * 100 + (s[index + 1] - '0') * 10 + s[index + 2] - '0' <= 255) {
		temp[index + step - 1] = s[index];		//�ѷ��ϵ���3���ַ��ŵ���ʱ�ַ����ĵ�step����
		temp[index + step] = s[index + 1];
		temp[index + step + 1] = s[index + 2];
		temp[index + step + 2] = '.';			//��'.',��һ�ν�����������һ��
		dfs(s, s_len, returnStr, returnSize, step + 1, index + 3, temp);//�����ݹ飬������һ��
	}
	//��step = 5ʱ��˵���Ķ��Ѿ����꣬�ô���temp�е��ַ�����
	if (step == 5) {
		returnStr[*returnSize] = (char*)malloc(sizeof(char) * (s_len + 4));
		temp[index + step - 2] = '\0';		//�����һλ�ġ�.���ĳɡ�\0��
		strcpy(returnStr[*returnSize], temp);//��������Ҫ���ص�������
		(*returnSize)++;	//�Ϸ��ַ����ĸ�����1
		return;
	}
}

char** RestoreIpAddresses(char* s, int* returnSize) {
	int s_len = strlen(s);		//�ַ���s�ĳ���
	if (s_len < 4 || s_len>12)//������Ȳ��Ϸ���ֱ�ӷ���NULL
		return NULL;
	char** returnStr = (char**)malloc(sizeof(char*) * 81);//Ϊ���غϷ�ip���ٿռ�
	char* temp = (char*)malloc(sizeof(char) * (s_len + 4));//����һ����ʱ�������洢�õ��ĺϷ�ip
	*returnSize = 0;				//���غϷ�ip�ĸ���
	int step = 1;					//step��ʾ��������1��4����step=5ʱ˵��ip��4�ζ��������ˣ����ء�
	int index = 0;					//index�ƶ�����s�����ܹ���¼���ʵ���s�ĵڼ����ַ�
	dfs(s, s_len, returnStr,returnSize, step, index, temp);
	return returnStr;
}