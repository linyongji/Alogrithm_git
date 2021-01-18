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
	char** ret = (char**)malloc(sizeof(char*) * 1024);//����һ������ָ�룬��Ϊ����ֵ���ض�ά�ַ�������
	*returnSize = 0;//���������ά�ַ��������Ԫ�ظ���
	int buf[1024] = { 0 };//�������ջ���
	get_path(ret, root, returnSize, buf, 0);
	return ret;
}
void free_tree3(TreeNode3* T)//�����ͷ�
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
int str_device2(CString str, char(*return_str)[50])
{
	int value_count = 0;
	char* token;	//��ű��и��ĵ�һ���Ӵ�
	char Section_value[500] = { 0 };//���numsת����string���͵Ľ��
	memset(Section_value, 0, sizeof(char) * 500);
	strcpy(Section_value, str);//��CString���͵��ַ���ת����char���ͣ���������и��ַ���
	//����и�ĵ�һ���ַ���
	token = strtok(Section_value, ",");
	/* ������ȡ���������ַ��� */
	while (token != NULL) {
		strcpy(return_str[value_count], token);
		token = strtok(NULL, ",");
		value_count++;		//��¼���˶��ٸ�Ԫ��
	}
	return value_count;	//���������׵�ַ
}