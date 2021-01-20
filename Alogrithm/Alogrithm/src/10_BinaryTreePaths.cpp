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
	if (NULL == root) {//������ڵ�ΪNULL��ֱ�ӷ���
		return;
	}
	if (NULL == root->left && NULL == root->right) {//�������������Ϊ��
		//˵���ҵ�·�ˣ��ѻ������Ĵ�ӡ��������
		char* str = (char*)malloc(1024);
		int len = 0;						//����len��Ϊƫ����
		for (int i = 0; i < local; i++)		//���ҵ���һ��·��ƴ��������
		{									
			len += sprintf(str + len, "%d->", buf[i]);//sprintf���سɹ�д���ַ�����
		}									
		sprintf(str + len, "%d", root->val);//ƴ��Ҷ�ڵ�����һ��ֵ
		array[(*returnSize)++] = str;		//��ƴ�Ӻõ��ַ�����ַ�ŵ�Ҫ���ص�array��
	}
	else {//�������������Ϊ��
		// �ѵ�ǰ��ֵд��buf���㼶+1�������ݹ���·
		buf[local++] = root->val;
		get_path(array, root->left, returnSize, buf, local);
		get_path(array, root->right, returnSize, buf, local);
	}
}
//��Ŀ������һ�����������������дӸ��ڵ㵽Ҷ�ӽڵ��·����
//˼·���ݹ����������������sprintf������·������ƴ�ӣ�ƴ�ӵ�·����Ϊ�ַ�������ڶ�ά�ַ���������
char** binaryTreePaths(struct TreeNode3* root, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * 1024);//����һ������ָ�룬��Ϊ����ֵ���ض�ά�ַ�������
	*returnSize = 0;//���������ά�ַ��������Ԫ�ظ���
	int buf[1024] = { 0 };//�������ջ��壬���е�val
	get_path(ret, root, returnSize, buf, 0);//���ú������Զ��������еݹ����
	return ret;
}
//�ͷŶ�����
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
