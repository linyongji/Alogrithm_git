#include "../include/7_MaxDepth.h"

TreeNode2* CreatBitTree2(char str[][50], int return_count)
{
	if (str == NULL || return_count <= 0) {
		return NULL;
	}
	TreeNode2* head = (TreeNode2*)malloc(sizeof(TreeNode2));
	if (NULL == head) {
		return NULL;
	}
	head->val = _ttoi(str[0]);
	CreatBitTreeNode2(str, return_count, head, 0);
	return head;
}
void CreatBitTreeNode2(char str[][50], int return_count, TreeNode2* cur, int curIndex)
{
	if (str == NULL || return_count <= 0 || cur == NULL || curIndex >= return_count || curIndex < 0) {
		return;
	}
	int last = return_count - 1;
	if ((2 * curIndex + 1 <= last) && strcmp(str[2 * curIndex + 1], "NULL")) {
		cur->left = (TreeNode2*)malloc(sizeof(TreeNode2));
		if (NULL == cur->left) {
			return;
		}
		cur->left->val = _ttoi(str[2 * curIndex + 1]);
	}
	else {
		cur->left = NULL;
	}
	if ((2 * curIndex + 2 <= last) && strcmp(str[2 * curIndex + 2], "NULL")) {
		cur->right = (TreeNode2*)malloc(sizeof(TreeNode2));
		if (NULL == cur->right) {
			return;
		}
		cur->right->val = _ttoi(str[2 * curIndex + 2]);
	}
	else {
		cur->right = NULL;
	}
	CreatBitTreeNode2(str, return_count, cur->left, 2 * curIndex + 1);
	CreatBitTreeNode2(str, return_count, cur->right, 2 * curIndex + 2);
}
//返回二叉树中，最大深度
int MaxDepth(struct TreeNode2* root)
{
	int Depth = 0;
	int L1, L2;
	if (NULL == root) {//根节点为NULL，返回0
		return 0;
	}//左右子树都为NULL，返回1
	else if ((NULL == root->left) && (NULL == root->right)) {
		return 1;
	}//左子树不为NULL，右子树为NULL，继续搜索左子树
	else if ((NULL != root->left) && (NULL == root->right)) {
		Depth = MaxDepth(root->left);
	}//右子树不为NUULL，左子树为NULL，继续搜索右子树
	else if ((NULL == root->left) && (NULL != root->right)) {
		Depth = MaxDepth(root->right);
	}//如果左右子树都不为NULL，左右子树继续搜索
	else {
		L1 = MaxDepth(root->left);
		L2 = MaxDepth(root->right);
		Depth = fmax(L1, L2);//返回左右子树中，较大的一个
	}
	return Depth + 1;//每次搜索完，对Depth进行累加，最后返回。
}
void free_tree2(TreeNode2* T)//后序释放
{
	if (!T) {
		return;
	}
	if (T->left) {
		free_tree2(T->left);
	}
	if (T->right) {
		free_tree2(T->right);
	}
	if (T) {
		free(T);
		T = NULL;
	}
}