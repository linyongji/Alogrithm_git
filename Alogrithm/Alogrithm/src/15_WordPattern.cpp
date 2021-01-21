#include "../include/15_WordPattern.h"

//题目：给定一种规律pattern和一个字符串str，判断str是否遵循相同的规律。
//思路：定义结构体数组，把对应的字符和字符串存起来，然后判断字符相同的元素，对应的字符串是否也相等
bool WordPattern(char* pattern, char* s) {
	int patt_len = strlen(pattern);//存放pattern的长度
	int s_len = 0;					//存放s的长度
	char* token;					//切割字符串用，临时存储字符串
	ComPose* arr = (ComPose*)malloc(sizeof(ComPose) * patt_len);//为结构体数组开辟空间，这里以pattern的长度开辟大小
	token = strtok(s, " ");			//以空格切割字符串s，把第一个字符串放到strtok中
	while (token != NULL) {			//继续切割，直到字符串s为NULL
		if (s_len == patt_len)		//s字符串个数超大于pattern字符个数，返回false
			return false;	
		arr[s_len].ch = pattern[s_len];//把pattern中的字符挨个放到结构体数组中的char ch中
		arr[s_len].str = (char*)malloc(sizeof(char) * strlen(token));//为结构体中的 char *str开辟空间
		strcpy(arr[s_len].str, token);	//把拆分到的字符串挨个拷贝到结构体数组中的char *str中
		token = strtok(NULL, " ");		//继续拆分
		s_len++;						//统计字符串子串的个数
	}
	if (s_len != patt_len)				//s字符串个数小于pattern字符个数，返回false
		return false;
	for (int i = 0; i < s_len; i++) {	//找结构体数组中ch相等的元素
		for (int j = 1; j < s_len ; j++) {
			if ((arr[i].ch - arr[j].ch == 0) && (strcmp(arr[i].str, arr[j].str) != 0))//如果ch对应相等的两个元素，str不相等，返回false
				return false;
			else if ((arr[i].ch - arr[j].ch != 0) && (strcmp(arr[i].str, arr[j].str) == 0))//ch不相等的两个元素，str相等，返回false
				return false;
		}
	}
return true;	//上面条件都不满足，返回false。
}