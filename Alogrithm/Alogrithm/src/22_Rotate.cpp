#include "../include/22_Rotate.h"
//题目：给定一个数组，将数组中的元素向右移动k个位置，其中k是非负数。

//方法一：创建一个新的数组，把每个元素按照需要移动的位置，依次放到存放到新的数组中。
void Rotate1(int* nums, int numsSize, int k) {
	int* cpynums=(int *)malloc(sizeof(int) * numsSize);	//开辟新的数组
	for (int i = 0; i < numsSize; i++) {				//i从0开始，当i和numsSize相等时结束
		cpynums[(i+k)%numsSize] = nums[i];				//从nums数组的第一个数到最后一个数依次放到新数组的第i+k的位置
	}
	for (int i = 0; i < numsSize; i++) {				//把移动完成的数组拷贝给原数组
		nums[i] = cpynums[i];
	}
}

//方法二使用到的数组逆置函数，功能是逆置数组中指定连续元素
void reverse(int* nums, int start, int end) {
	int temp = 0;
	while (start < end) {
		temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}
//方法二：先把整个数组逆置，再把0到k-1逆置，再把k到numsSize-1逆置，得到翻转后的数组
void Rotate2(int* nums, int numsSize, int k) {
	k = k % numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k ,numsSize - 1);
	for (int i = 0; i < numsSize; i++) {				//把移动完成的数组拷贝给原数组
		printf("%d ", nums[i]);
	}
}

//方法三：环装替换法
//1,直接遍历数组，将当前位置的值替换到被替换的位置，被替换位置的值保存在变量change中，进行下一次替换
//2,但是如果 numsSize 正好是 k 的倍数时，就会出现循环处理相同位置的数据
//3,因此每个遇到循环之后需要加1，进行下一个位置的移动

void Rotate3(int* nums, int numsSize, int k) {
	int count = 0;								//用来计算访问元素的次数，最多为numsSize次
	for (int i = 0; count < numsSize; i++) {	//i的作用：当numsSize为k的倍数，循环处理相同位置数据时，把待处理的数据移动到下一位置
		int temp = 0;							//临时变量，交换数据时用
		int change = nums[i];					//存放第一个需要替换的值
		do
		{
			count++;							//count实际从1开始的
			temp = change;						//交换当前位置的值和要被替换位置的值，被替换位置的值继续保存在change中，准备下一次替换
			change = nums[(k * count + i) % numsSize];
			nums[(k * count + i) % numsSize] = temp;
			if ((count * k)%numsSize == 0)		//当numsSize 正好是 k 的倍数时，跳出循环，
				break;
		} while (count != numsSize);			//如果count和numsSize相等，说明该结束了
	}
}