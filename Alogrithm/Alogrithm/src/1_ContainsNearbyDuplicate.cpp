#include <stdio.h>
#include <stdlib.h>
#include "../include/1_ContainsNearbyDuplicate.h"

//解题思路：先排序,再查找，再判断
typedef struct node_t { //定义结构体数组类型
	int value;			//存放 数组值
	int index;			//存放 下标
}node;
int cmp(const void* a, const void* b) //qsort 里的cmp函数 
{
	if (((node*)a)->value < ((node*)b)->value)
		return -1;
	else if (((node*)a)->value == ((node*)b)->value)
		return 0;
	else
		return 1;
}
int fun(int a, int b) //两数相减求绝对值
{
	int t;
	t = a - b;
	if (t < 0)
		t = t - 2 * t;
	return t;
}

bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	node* arr = NULL;		//定义一个node 指针
	int i = 0;
	int j = 0;
	arr = (node*)malloc(sizeof(node) * numsSize);//为arr指针分配足够空间，用来保存数组
	if (NULL == arr)
	{
		printf("内存分配失败\n");
	}
	else{
		for (i = 0; i < numsSize; i++)//遍历数组nums，把nums里的值和对应的下标保存在arr中
		{
			arr[i].value = nums[i];
			arr[i].index = i;
		}
		qsort(arr, numsSize, sizeof(node), cmp);//调用c库函数qsort，对得到的数组arr进行排序
		for (i = 0; i < numsSize; i++)//对排好序的数组arr遍历，寻找返回true的条件
		{
			for (j = i + 1; j < numsSize; j++)
			{
				if (arr[i].value == arr[j].value) //第i个元素和i后面的元素作比较，判断值是否相等
				{
					if (fun(arr[j].index, arr[i].index) <= k)//调用fun，求得下标差的绝对值，和k作比较
					{
						return true;
					}
				}
				else {//不符合则跳出循环
					break;
				}
			}
		}
	}
	free(arr);//释放arr
	return false;//循环执完以后，说明没有符合的结果，则返回false；
}

