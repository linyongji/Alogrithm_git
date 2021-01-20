#include "../include/5_MinDepth.h"
//题目：求一个二叉树的最小深度
//思路：递归遍历这棵树

//创建一棵二叉树，入参为字符串数组。
TreeNode* CreatBitTree(char str[][50], int return_count)
{	//如果传进来的字符串数组为空，则返回空
	if (str == NULL || return_count <= 0) {
		return NULL;
	}//给给根节点开辟一片空间
	TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == head) {//如果内存申请失败，返回NULL
		return NULL;
	}//给根节点的数据域赋值，
	head->val = _ttoi(str[0]);
	CreatBitTreeNode1(str, return_count, head, 0);//通过调用函数，给根节点以外的子树赋值
	return head;//返回根节点
}
//函数功能是给根节点以外的子树赋值，入参为字符串数组、根节点、标志位
void CreatBitTreeNode1(char str[][50], int return_count, TreeNode* cur, int curIndex)
{	//赋值前判空
	if (str == NULL || return_count <= 0 || cur == NULL || curIndex >= return_count || curIndex < 0) {
		return;
	}//递归赋值
	int last = return_count - 1;
	if ((2 * curIndex + 1 <= last) && strcmp(str[2 * curIndex + 1], "NULL")) {
		cur->left = (TreeNode*)malloc(sizeof(TreeNode));
		if (NULL == cur->left) {
			return;
		}
		cur->left->val = _ttoi(str[2 * curIndex + 1]);
	}
	else {
		cur->left = NULL;
	}
	if ((2 * curIndex + 2 <= last) && strcmp(str[2 * curIndex + 2], "NULL")) {
		cur->right = (TreeNode*)malloc(sizeof(TreeNode));
		if (NULL == cur->right) {
			return;
		}
		cur->right->val = _ttoi(str[2 * curIndex + 2]);
	}
	else {
		cur->right = NULL;
	}
	CreatBitTreeNode1(str, return_count, cur->left, 2 * curIndex + 1);
	CreatBitTreeNode1(str, return_count, cur->right, 2 * curIndex + 2);
}
//找二叉树的最小深度
int MinDepth(struct TreeNode* root)
{
	int Depth = 0;
	int L1, L2;
	if (NULL == root) {//如果根节点为空，返回0
		return 0;
	}//如果左右子树为空，返回1
	else if ((NULL == root->left) && (NULL == root->right)) {
		return 1;
	}//如果左子树不为空，右子树为空，继续搜索左子树
	else if ((NULL != root->left) && (NULL == root->right)) {
		Depth = MinDepth(root->left);
	}//如果左子树为空，右子树不为空，继续搜索右子树
	else if ((NULL == root->left) && (NULL != root->right)) {
		Depth = MinDepth(root->right);
	}//如果都不为空，则两边搜索
	else {
		L1 = MinDepth(root->left);
		L2 = MinDepth(root->right);
		Depth = fmin(L1, L2);//把左右子树中，深度较小的一个给Depth
	}
	return Depth + 1;//每次搜索完，把搜索到的结果进行累加
}

//释放二叉树
void free_tree(TreeNode* T)//后序释放
{
	if (!T) {
		return;
	}
	if (T->left) {
		free_tree(T->left);
	}
	if (T->right) {
		free_tree(T->right);
	}
	if (T) {
		free(T);
		T = NULL;
	}
}