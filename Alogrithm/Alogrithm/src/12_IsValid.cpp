#include "../include/12_IsValid.h"
#pragma warning(disable:6385)
#pragma warning(disable:6386)
//˼·���������Ž�ջ�������ź����������ν���ƥ�䡣
bool IsValid(char* s) {
	int s_len = strlen(s);//����һ��int����������ַ�������
	char* stack = (char*)malloc(sizeof(char) * (s_len + 2));//����һ��char*ָ������ģ��һ��ջ
	int top = 0;//����һ����������������stack
	if (s_len % 2 != 0) {//����ַ�������Ϊ�����Ļ����϶���ƥ�䣬ֱ�ӷ���false
		return false;
	}
	for (int i = 0; i < s_len; i++) {//ѭ�������ַ��������ַ���ջ
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {//����������ţ�����ջ
			top++;//top����
			stack[top] = s[i];//��ջ
		}//����������ţ����ǰһ���������Ƚϣ���ͬ˵��ƥ�䣬topǰ�ƣ�
		else if ((s[i] == ')' && stack[top] == '(') || (s[i] == '}' && stack[top] == '{') || (s[i] == ']' && stack[top] == '[')) {
			top--;
		}
		else {//ǰ��ķ��Ų�ƥ�䣬�����Ҳ���������false
			return false;
		}
	}//�������Ժ��ж�top�ǲ����Ƶ��ʼ��λ�ã�
	if (top == 0) {//���򷵻�true
		return true;
	}
	return false;//���򷵻�false
	free(stack);
}