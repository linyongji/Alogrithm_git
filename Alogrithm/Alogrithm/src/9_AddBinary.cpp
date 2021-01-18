#include"../include/9_AddBinary.h"

char* AddBinary(char* a, char* b)
{
	int len_a = strlen(a) - 1;//存放字符串a的长度
	int len_b = strlen(b) - 1;//存放字符串b的长度
	int carry = 0;//进位标志
	int len = len_a > len_b ? len_a : len_b;//获取两个字符串中长度较长的哪一个

	char* pstr = (char*)malloc(sizeof(char) * (len + 3));//定义一个指针作为返回值，多分配两个空间是为了防止有进位和字符结尾标志\0
	if (NULL == pstr)
		return NULL;
	pstr[len + 2] = '\0';//给字符串末尾加\0
	len = len + 1;
	while ((len_a >= 0) || (len_b >= 0)) {//只要两个字符串有一个没遍历完，则继续遍历，这里从两个字符串的末尾开始遍历
		int sum = carry;//sum用来保存a[len_a]和b[len_b]和carry相加的结果，sum可以为：0,1,2,3
		sum += (len_a >= 0 ? a[len_a] - '0' : 0);
		sum += (len_b >= 0 ? b[len_b] - '0' : 0);
		carry = sum / 2;//当sum=2或3时需要进位，2表示：a[a_len]和b[b_len]相加要进位，3表示：上一位需要进位
		pstr[len] = '0' + sum % 2;//给pstr[len]赋值，
		len_a--, len_b--, len--;
	}
	//判断要不要加前导0
	if (carry == 0) {
		return (pstr + 1);//指针加一，表示指针向后移动，在这里如果不进位的话指针就指向非0的下一位。
	}
	else {
		pstr[0] = '1';
		return pstr;
	}
	//free(pstr);
}