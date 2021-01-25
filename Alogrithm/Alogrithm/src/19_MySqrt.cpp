#include "../include/19_MySqrt.h"
//题目：实现 int sqrt(int x) 函数，计算并返回 x 的平方根，其中 x 是非负整数。
//      由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//思路：使用二分法进行查找，先确定上下限和中间值，对中间值进行平方，然后和x作比较
//		如果中间值的平方比x小，low加一缩小搜索范围；如果相等则刚好找到；否则high减一缩小搜索范围
int MySqrt(int x) {
	if (x < 2) {//如果入参为0,1，直接返回原数
		return x;
	}//因为一个数的平方一定大于等于这个数的二倍（0,1除外），所以上限缩小为x/2
	int low = 1, high = x / 2,mid = 0;		//定义下限，上限，中间值
	while (low <= high)						//循环终止条件，当左界限比右界限大时，跳出循环
	{
		mid = (low + high) / 2;				//取low和high的中间值mid
		if (mid == x / mid) {				//判断mid*nid和x是否相等，因为考虑到乘法溢出，这里写为mid == x/mid
			return mid;						//相等说明找到，直接返回			
		}
		else if ( mid < x / mid) {			//如果mid*mid小于x
			low = mid + 1;					//下限上移
		}
		else {								//如果mid*mid大于x
			high = mid - 1;					//上限下移
		}
	}										//循环结束时，low>high，也就是说 low平方>x>high平方，这里小数部分省去
	return high;							//所以返回的high就是需要的值
}