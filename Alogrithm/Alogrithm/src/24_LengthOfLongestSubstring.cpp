#include "../include/24_LengthOfLongestSubstring.h"
//题目：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
//思路:	1.定义一个Index[128]，每个字符的ASCII码在Index中对应一个int数，这个int数保存每个字符在字符串s出现的位置
//		2.定义一个 int start，用来保存子串每次的初始位置
//		3.挨个访问字符串s，当某个字符不是第一次出现且在子串起始位置之后，获取重复字符之间子串长度：i - start，和之前保存最长的子串比较，保存较长的那一个
//		4.更新start到Index[s[i]]，该重复字符上一次出现位置的下一个字符
//		5.循环获取子串，求长度，比较得到长的字符串
//		6.当最后一个字符找不到重复字符时，计算最后一个start到最后一个字符的长度
int LengthOfLongestSubstring(char* s) {
	int Index[128] = { 0 };	//每个字符的ASCII码作为数组的下标，Index用来存储每个字符在字符串s中的位置
	int len = 0;		//存放子串的长度，每次遇到有重复字符时重新计算
	int max = 0;		//存放最长子串，作为返回值
	int i = 0;			//变量i，用来访问字符串s
	int start = 0;		//子串起始位置的下标，每次遇到重复子串时更新位置
	for ( i = 0; i < strlen(s); i++) {
		if (Index[s[i]] > start) {		//判断字符是不是第一次出现，且比起始位置要大
			len = i - start;			//获得当前子串的长度
			if (len > max) {			//如果当前子串比原来的子串长，则更新为当前子串
				max = len;
			}
			start = Index[s[i]];		//更新子串的起始位置:该重复字符上一次出现位置的下一个字符
		}
		Index[s[i]] = i + 1;			//把当前字符在字符串s中的位置放到Index中，如果字符多次出现就更新为最后出现的位置
	}
	len = i - start;					//如果遍历到最后一个字符，但是没找到重复的字符，则计算最后一个子串的长度
	return len > max ? len : max;
}




