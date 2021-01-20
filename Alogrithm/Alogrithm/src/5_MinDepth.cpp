#include "../include/5_MinDepth.h"
//��Ŀ����һ������������С���
//˼·���ݹ���������

//����һ�ö����������Ϊ�ַ������顣
TreeNode* CreatBitTree(char str[][50], int return_count)
{	//������������ַ�������Ϊ�գ��򷵻ؿ�
	if (str == NULL || return_count <= 0) {
		return NULL;
	}//�������ڵ㿪��һƬ�ռ�
	TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == head) {//����ڴ�����ʧ�ܣ�����NULL
		return NULL;
	}//�����ڵ��������ֵ��
	head->val = _ttoi(str[0]);
	CreatBitTreeNode1(str, return_count, head, 0);//ͨ�����ú����������ڵ������������ֵ
	return head;//���ظ��ڵ�
}
//���������Ǹ����ڵ������������ֵ�����Ϊ�ַ������顢���ڵ㡢��־λ
void CreatBitTreeNode1(char str[][50], int return_count, TreeNode* cur, int curIndex)
{	//��ֵǰ�п�
	if (str == NULL || return_count <= 0 || cur == NULL || curIndex >= return_count || curIndex < 0) {
		return;
	}//�ݹ鸳ֵ
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
//�Ҷ���������С���
int MinDepth(struct TreeNode* root)
{
	int Depth = 0;
	int L1, L2;
	if (NULL == root) {//������ڵ�Ϊ�գ�����0
		return 0;
	}//�����������Ϊ�գ�����1
	else if ((NULL == root->left) && (NULL == root->right)) {
		return 1;
	}//�����������Ϊ�գ�������Ϊ�գ���������������
	else if ((NULL != root->left) && (NULL == root->right)) {
		Depth = MinDepth(root->left);
	}//���������Ϊ�գ���������Ϊ�գ���������������
	else if ((NULL == root->left) && (NULL != root->right)) {
		Depth = MinDepth(root->right);
	}//�������Ϊ�գ�����������
	else {
		L1 = MinDepth(root->left);
		L2 = MinDepth(root->right);
		Depth = fmin(L1, L2);//�����������У���Ƚ�С��һ����Depth
	}
	return Depth + 1;//ÿ�������꣬���������Ľ�������ۼ�
}

//�ͷŶ�����
void free_tree(TreeNode* T)//�����ͷ�
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