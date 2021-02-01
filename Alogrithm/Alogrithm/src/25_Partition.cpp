#include "../include/25_Partition.h"
#include <stdio.h>
//��Ŀ������һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ�
//		���ڴ��ڻ���� x �Ľڵ�֮ǰ����Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
//˼·��������������,�ҵ�ÿ���ڵ��val���ض�ֵx�Ƚ�
//		����һ��large����������ض�ֵx��Ľڵ㣻����һ��small����������ض�ֵxС�Ľڵ�
//		�������Ժ��large����ӵ�small����ĺ��棬����small����������Ҫ�Ľ��

struct ListNode* Partition( struct ListNode* head, int x) {
	struct ListNode* small = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* large = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* smallHead = small;	//����small�����ͷ���
	struct ListNode* largeHead = large;	//����large�����ͷ���
	while (NULL != head) {				//����head����
		if (head->val < x) {			//�ѵ�ǰ�ڵ��ֵ�ó�����x���Ƚ�,���С��x��
			small->next = head;			//�ѵ�ǰ�ڵ����ӵ�small������
			small = small->next;		//small����ָ����һ���ڵ㣬Ϊ������һ���ڵ���׼��
		}
		else {							//�������x
			large->next = head;			//�ѵ�ǰ�ڵ����ӵ�large������
			large = large->next;		//small����ָ����һ���ڵ㣬Ϊ������һ���ڵ���׼��
		}
		head = head->next;				//ָ����һ���ڵ�
	}
	large->next = NULL;					
	small->next = largeHead->next;		//��large�������ӵ�small�������
	return smallHead->next;				//����small����
}
//�������飬������ڵ㸳ֵ
void CreatListNode(int *arr, int len, struct ListNode* head) {
	head->val = arr[0];
	for (int i = 1; i < len; i++) {
		head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		head = head->next;
		head->val = arr[i];
	}
	head->next = NULL;

}