#include "../include/20_MoveZeroes.h"
//题目：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//思路：定义两个变量left和right，开始时都指向数组的头部
//		right用来访问数组的每一个元素，left指向数组从头到尾的第一个0
//		如果nums[right]不为0，则交换两数，right和left都向后移动
//		如果nums[right]为0，则left指向了0，right指向下一个数
void MoveZeroes(int* nums, int numsSize) {
	int left = 0, right = 0, temp = 0;
	while (right < numsSize) {		//当right和数组长度相等时退出
		if (nums[right] != 0) {		//判断元素是否为0，不是则交换，两个指针同时移动；为0则只有right移动，left指向了0
			temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
		}
		right++;
	}

}