#include "../include/10_BinaryTreePaths.h"


void CreatBitTreeNode3(char str[][50], int return_count, TreeNode3* cur, int curIndex)
{
	if (str == NULL || return_count <= 0 || cur == NULL || curIndex >= return_count || curIndex < 0) {
		return;
	}
	int last = return_count - 1;
	if ((2 * curIndex + 1 <= last) && strcmp(str[2 * curIndex + 1], "NULL")) {
		cur->left = (TreeNode3*)malloc(sizeof(TreeNode3));
		if (NULL == cur->left) {
			return;
		}
		cur->left->val = _ttoi(str[2 * curIndex + 1]);
	}
	else {
		cur->left = NULL;
	}
	if ((2 * curIndex + 2 <= last) && strcmp(str[2 * curIndex + 2], "NULL")) {
		cur->right = (TreeNode3*)malloc(sizeof(TreeNode3));
		if (NULL == cur->right) {
			return;
		}
		cur->right->val = _ttoi(str[2 * curIndex + 2]);
	}
	else {
		cur->right = NULL;
	}
	CreatBitTreeNode3(str, return_count, cur->left, 2 * curIndex + 1);
	CreatBitTreeNode3(str, return_count, cur->right, 2 * curIndex + 2);
}
TreeNode3* CreatBitTree3(char str[][50], int return_count)
{
	if (str == NULL || return_count <= 0) {
		return NULL;
	}
	TreeNode3* head = (TreeNode3*)malloc(sizeof(TreeNode3));
	if (NULL == head) {
		return NULL;
	}
	head->val = _ttoi(str[0]);
	CreatBitTreeNode3(str, return_count, head, 0);
	return head;
}
void get_path(char** array, struct TreeNode3* root, int* returnSize, int* buf, int local)
{
	if (NULL == root) {
		return;
	}
	if (!root->left && !root->right) {
		char* str = (char*)malloc(1024);
		int len = 0;
		for (int i = 0; i < local; i++)
		{
			len += sprintf(str + len, "%d->", buf[i]);
		}
		sprintf(str + len, "%d", root->val);
		array[(*returnSize)++] = str;
	}
	else {
		buf[local++] = root->val;
		get_path(array, root->left, returnSize, buf, local);
		get_path(array, root->right, returnSize, buf, local);
	}
}
char** binaryTreePaths(struct TreeNode3* root, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * 1024);//定义一个二级指针，作为返回值返回二维字符串数组
	*returnSize = 0;//用来保存二维字符串数组的元素个数
	int buf[1024] = { 0 };//用来接收缓冲
	get_path(ret, root, returnSize, buf, 0);
	return ret;
}
void free_tree3(TreeNode3* T)//后序释放
{
	if (!T) {
		return;
	}
	if (T->left) {
		free_tree3(T->left);
	}
	if (T->right) {
		free_tree3(T->right);
	}
	if (T) {
		free(T);
		T = NULL;
	}
}
