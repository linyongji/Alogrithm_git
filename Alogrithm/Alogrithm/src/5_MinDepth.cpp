#include "../include/5_MinDepth.h"

TreeNode* CreatBitTree(char str[][50], int return_count)
{
	if (str == NULL || return_count <= 0) {
		return NULL;
	}
	TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == head) {
		return NULL;
	}
	head->val = _ttoi(str[0]);
	CreatBitTreeNode1(str, return_count, head, 0);
	return head;
}
void CreatBitTreeNode1(char str[][50], int return_count, TreeNode* cur, int curIndex)
{
	if (str == NULL || return_count <= 0 || cur == NULL || curIndex >= return_count || curIndex < 0) {
		return;
	}
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
int MinDepth(struct TreeNode* root)
{
	int Depth = 0;
	int L1, L2;
	if (NULL == root) {
		return 0;
	}
	else if ((NULL == root->left) && (NULL == root->right)) {
		return 1;
	}
	else if ((NULL != root->left) && (NULL == root->right)) {
		Depth = MinDepth(root->left);
	}
	else if ((NULL == root->left) && (NULL != root->right)) {
		Depth = MinDepth(root->right);
	}
	else {
		L1 = MinDepth(root->left);
		L2 = MinDepth(root->right);
		Depth = fmin(L1, L2);
	}
	return Depth + 1;
}
void free_tree(TreeNode* T)//ºóÐòÊÍ·Å
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