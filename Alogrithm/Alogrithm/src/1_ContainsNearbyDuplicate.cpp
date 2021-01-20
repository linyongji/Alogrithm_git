#include <stdio.h>
#include <stdlib.h>
#include "../include/1_ContainsNearbyDuplicate.h"

//����˼·��������,�ٲ��ң����ж�
typedef struct node_t { //����ṹ����������
	int value;			//��� ����ֵ
	int index;			//��� �±�
}node;
int cmp(const void* a, const void* b) //qsort ���cmp���� 
{
	if (((node*)a)->value < ((node*)b)->value)
		return -1;
	else if (((node*)a)->value == ((node*)b)->value)
		return 0;
	else
		return 1;
}
int fun(int a, int b) //������������ֵ
{
	int t;
	t = a - b;
	if (t < 0)
		t = t - 2 * t;
	return t;
}

bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	node* arr = NULL;		//����һ��node ָ��
	int i = 0;
	int j = 0;
	arr = (node*)malloc(sizeof(node) * numsSize);//Ϊarrָ������㹻�ռ䣬������������
	if (NULL == arr)
	{
		printf("�ڴ����ʧ��\n");
	}
	else{
		for (i = 0; i < numsSize; i++)//��������nums����nums���ֵ�Ͷ�Ӧ���±걣����arr��
		{
			arr[i].value = nums[i];
			arr[i].index = i;
		}
		qsort(arr, numsSize, sizeof(node), cmp);//����c�⺯��qsort���Եõ�������arr��������
		for (i = 0; i < numsSize; i++)//���ź��������arr������Ѱ�ҷ���true������
		{
			for (j = i + 1; j < numsSize; j++)
			{
				if (arr[i].value == arr[j].value) //��i��Ԫ�غ�i�����Ԫ�����Ƚϣ��ж�ֵ�Ƿ����
				{
					if (fun(arr[j].index, arr[i].index) <= k)//����fun������±��ľ���ֵ����k���Ƚ�
					{
						return true;
					}
				}
				else {//������������ѭ��
					break;
				}
			}
		}
	}
	free(arr);//�ͷ�arr
	return false;//ѭ��ִ���Ժ�˵��û�з��ϵĽ�����򷵻�false��
}

