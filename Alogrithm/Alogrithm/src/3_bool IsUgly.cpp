
#include "../include/3_bool IsUgly.h "  
//判断一个数是否为丑数（能被2 3 5整除的数），能返回true，不能返回false
//思路：对入参循环判断%2、%3、%5是否为0，是则除相应的数，否则跳出循环，对num判断，
//为1，则说明能被2、3、5除尽，是丑数，否则不是。
bool IsUgly(int num)
{	//入参判断，如果小于等于0直接返回false
	if (num <= 0) {
		return false;
	}
	while (1) {//对num循环判断并做相应的运算，直到三个条件都不满足退出循环
		if (num % 2 == 0) {
			num = num / 2;
		}
		else if (num % 3 == 0) {
			num = num / 3;
		}
		else if (num % 5 == 0) {
			num = num / 5;
		}
		else {
			break;
		}
	}
	if (num == 1) {//对最后的num判断，如果为1则说明能被除尽，是丑数；否则不是丑数返回false
		return true;
	}
	return false;
}