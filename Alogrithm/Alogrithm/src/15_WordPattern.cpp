#include "../include/15_WordPattern.h"

//��Ŀ������һ�ֹ���pattern��һ���ַ���str���ж�str�Ƿ���ѭ��ͬ�Ĺ��ɡ�
//˼·������ṹ�����飬�Ѷ�Ӧ���ַ����ַ�����������Ȼ���ж��ַ���ͬ��Ԫ�أ���Ӧ���ַ����Ƿ�Ҳ���
bool WordPattern(char* pattern, char* s) {
	int patt_len = strlen(pattern);//���pattern�ĳ���
	int s_len = 0;					//���s�ĳ���
	char* token;					//�и��ַ����ã���ʱ�洢�ַ���
	ComPose* arr = (ComPose*)malloc(sizeof(ComPose) * patt_len);//Ϊ�ṹ�����鿪�ٿռ䣬������pattern�ĳ��ȿ��ٴ�С
	token = strtok(s, " ");			//�Կո��и��ַ���s���ѵ�һ���ַ����ŵ�strtok��
	while (token != NULL) {			//�����иֱ���ַ���sΪNULL
		if (s_len == patt_len)		//s�ַ�������������pattern�ַ�����������false
			return false;	
		arr[s_len].ch = pattern[s_len];//��pattern�е��ַ������ŵ��ṹ�������е�char ch��
		arr[s_len].str = (char*)malloc(sizeof(char) * strlen(token));//Ϊ�ṹ���е� char *str���ٿռ�
		strcpy(arr[s_len].str, token);	//�Ѳ�ֵ����ַ��������������ṹ�������е�char *str��
		token = strtok(NULL, " ");		//�������
		s_len++;						//ͳ���ַ����Ӵ��ĸ���
	}
	if (s_len != patt_len)				//s�ַ�������С��pattern�ַ�����������false
		return false;
	for (int i = 0; i < s_len; i++) {	//�ҽṹ��������ch��ȵ�Ԫ��
		for (int j = 1; j < s_len ; j++) {
			if ((arr[i].ch - arr[j].ch == 0) && (strcmp(arr[i].str, arr[j].str) != 0))//���ch��Ӧ��ȵ�����Ԫ�أ�str����ȣ�����false
				return false;
			else if ((arr[i].ch - arr[j].ch != 0) && (strcmp(arr[i].str, arr[j].str) == 0))//ch����ȵ�����Ԫ�أ�str��ȣ�����false
				return false;
		}
	}
return true;	//���������������㣬����false��
}