#include "../include/25_Partition.h"
#include <stdio.h>
//题目：给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点
//		都在大于或等于 x 的节点之前。你应当保留两个分区中每个节点的初始相对位置。
//思路：遍历整个链表,找到每个节点的val和特定值x比较
//		定义一个large链表，保存比特定值x大的节点；定义一个small链表，保存比特定值x小的节点
//		遍历完以后把large链表接到small链表的后面，返回small链表，就是需要的结果

struct ListNode* Partition( struct ListNode* head, int x) {
	struct ListNode* small = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* large = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* smallHead = small;	//保存small链表的头结点
	struct ListNode* largeHead = large;	//保存large链表的头结点
	while (NULL != head) {				//遍历head链表
		if (head->val < x) {			//把当前节点的值拿出来和x作比较,如果小于x：
			small->next = head;			//把当前节点连接到small链表中
			small = small->next;		//small链表指向下一个节点，为连接下一个节点做准备
		}
		else {							//如果大于x
			large->next = head;			//把当前节点连接到large链表中
			large = large->next;		//small链表指向下一个节点，为连接下一个节点做准备
		}
		head = head->next;				//指向下一个节点
	}
	large->next = NULL;					
	small->next = largeHead->next;		//把large链表连接到small链表后面
	return smallHead->next;				//返回small链表
}
//传入数组，给链表节点赋值
void CreatListNode(int *arr, int len, struct ListNode* head) {
	head->val = arr[0];
	for (int i = 1; i < len; i++) {
		head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		head = head->next;
		head->val = arr[i];
	}
	head->next = NULL;

}