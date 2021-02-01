#pragma once
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* Partition(struct ListNode* head, int x);
void CreatListNode(int *arr, int len, struct ListNode* head);