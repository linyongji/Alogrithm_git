#include "../include/23_RestoreIpAddresses.h"
//题目：给定一个只包含数字的字符串，复原它并返回所有可能的IP地址格式。
//		有效的IP地址正好由四个整数（每个整数位于0到255之间组成），整数之间用 '.' 分隔。
//思路：由题知，一个合法ip地址分为四段，每一段都有三种情况，分别为：一位数、两位数、三位数，
//		这道题可以考虑使用递归的方法，把整个问题拆分为三个分支，步骤为：调用函数查找符合第一段的情况（如果
//		第一段是一位数 或两位数 或三位数 时 所剩字符长度符合合法ip地址要求）则继续使用本函数查找第二段
//		每次查找都会记录查找到了第几段，并把查到的合法ip放在临时字符串，第四段查完时把临时字符串拷贝到返回的字符串
//		数组中去，并记录合法ip的个数
void dfs(char* s, int s_len, char** returnStr,int *returnSize, int step, int index, char* temp) {
	//当某一段为1位数时，考虑剩下的字符能否组成合法ip（条件是：大于4-step  且小于 4-step乘3），符合条件走下面：
	if ((s_len - index - 1 >= 4 - step) && (s_len - index - 1 <= (4 - step) * 3)) {
		temp[index + step - 1] = s[index];		//把符合的这1个字符放到临时字符串的第step段中
		temp[index + step ] = '.';				//加'.',这一段结束，考虑下一段
		dfs(s, s_len, returnStr, returnSize, step + 1, index + 1, temp);//继续递归，考虑下一段
	}
	//当某一段为2位数时，考虑剩下的字符能否组成合法ip（条件是：大于4-step  且小于 4-step乘3 且不为0开头），符合条件走下面：
	if ((s_len - index - 2 >= 4 - step) && (s_len - index - 2 <= (4 - step) * 3) && s[index] != '0') {
		temp[index + step - 1] = s[index];		//把符合的这2个字符放到临时字符串的第step段中
		temp[index + step] = s[index+1];		
		temp[index + step + 1] = '.';			//加'.',这一段结束，考虑下一段
		dfs(s, s_len, returnStr, returnSize, step + 1, index + 2, temp);//继续递归，考虑下一段
	}
	//当某一段为3位数时，考虑剩下的字符能否组成合法ip（条件是：大于4-step  且 小于 4-step乘3 且 不为0开头 且 三个字符组成的
	//数字不能大于255），符合条件走下面：
	if ((s_len - index - 3 >= 4 - step) && (s_len - index - 3 <= (4 - step) * 3) && s[index] != '0' && (s[index] - '0') * 100 + (s[index + 1] - '0') * 10 + s[index + 2] - '0' <= 255) {
		temp[index + step - 1] = s[index];		//把符合的这3个字符放到临时字符串的第step段中
		temp[index + step] = s[index + 1];
		temp[index + step + 1] = s[index + 2];
		temp[index + step + 2] = '.';			//加'.',这一段结束，考虑下一段
		dfs(s, s_len, returnStr, returnSize, step + 1, index + 3, temp);//继续递归，考虑下一段
	}
	//当step = 5时，说明四段已经走完，该处理temp中的字符串了
	if (step == 5) {
		returnStr[*returnSize] = (char*)malloc(sizeof(char) * (s_len + 4));
		temp[index + step - 2] = '\0';		//把最后一位的‘.’改成‘\0’
		strcpy(returnStr[*returnSize], temp);//拷贝到需要返回的数组中
		(*returnSize)++;	//合法字符串的个数加1
		return;
	}
}

char** RestoreIpAddresses(char* s, int* returnSize) {
	int s_len = strlen(s);		//字符串s的长度
	if (s_len < 4 || s_len>12)//如果长度不合法，直接返回NULL
		return NULL;
	char** returnStr = (char**)malloc(sizeof(char*) * 81);//为返回合法ip开辟空间
	char* temp = (char*)malloc(sizeof(char) * (s_len + 4));//定义一个临时变量，存储得到的合法ip
	*returnSize = 0;				//返回合法ip的个数
	int step = 1;					//step表示段数，从1到4，当step=5时说明ip的4段都考虑完了，返回。
	int index = 0;					//index移动访问s，并能够记录访问到了s的第几个字符
	dfs(s, s_len, returnStr,returnSize, step, index, temp);
	return returnStr;
}