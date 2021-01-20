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
	if (NULL == root) {//如果根节点为NULL，直接返回
		return;
	}
	if (NULL == root->left && NULL == root->right) {//如果左右子树都为空
		//说明找到路了，把缓冲区的打印出来即可
		char* str = (char*)malloc(1024);
		int len = 0;						//这里len作为偏移量
		for (int i = 0; i < local; i++)		//把找到的一条路径拼接起来，
		{									
			len += sprintf(str + len, "%d->", buf[i]);//sprintf返回成功写入字符个数
		}									
		sprintf(str + len, "%d", root->val);//拼接叶节点的最后一个值
		array[(*returnSize)++] = str;		//把拼接好的字符串地址放到要返回的array中
	}
	else {//如果左右子树不为空
		// 把当前的值写进buf，层级+1，继续递归找路
		buf[local++] = root->val;
		get_path(array, root->left, returnSize, buf, local);
		get_path(array, root->right, returnSize, buf, local);
	}
}
//题目：给定一个二叉树，返回所有从根节点到叶子节点的路径。
//思路：递归遍历二叉树，利用sprintf函数对路径进行拼接，拼接的路径作为字符串存放在二维字符串数组中
char** binaryTreePaths(struct TreeNode3* root, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * 1024);//定义一个二级指针，作为返回值返回二维字符串数组
	*returnSize = 0;//用来保存二维字符串数组的元素个数
	int buf[1024] = { 0 };//用来接收缓冲，树中的val
	get_path(ret, root, returnSize, buf, 0);//调用函数，对二叉树进行递归遍历
	return ret;
}
//释放二叉树
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
