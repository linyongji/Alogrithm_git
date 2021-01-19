#include "../include/12_IsValid.h"
#pragma warning(disable:6385)
#pragma warning(disable:6386)
//思路：让左括号进栈，右括号和左括号依次进行匹配。
bool IsValid(char* s) {
	int s_len = strlen(s);//定义一个int变量，存放字符串长度
	char* stack = (char*)malloc(sizeof(char) * (s_len + 2));//定义一个char*指针用来模拟一个栈
	int top = 0;//定义一个变量，用来访问stack
	if (s_len % 2 != 0) {//如果字符串长度为奇数的话，肯定不匹配，直接返回false
		return false;
	}
	for (int i = 0; i < s_len; i++) {//循环遍历字符串，将字符入栈
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {//如果是左括号，则入栈
			top++;//top后移
			stack[top] = s[i];//入栈
		}//如果是右括号，则和前一个符号做比较，相同说明匹配，top前移；
		else if ((s[i] == ')' && stack[top] == '(') || (s[i] == '}' && stack[top] == '{') || (s[i] == ']' && stack[top] == '[')) {
			top--;
		}
		else {//前面的符号不匹配，或者找不到，返回false
			return false;
		}
	}//遍历完以后判断top是不是移到最开始的位置，
	if (top == 0) {//是则返回true
		return true;
	}
	return false;//否，则返回false
	free(stack);
}