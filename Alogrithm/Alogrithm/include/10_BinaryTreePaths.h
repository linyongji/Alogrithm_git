#pragma once
#include <atlstr.h>

struct TreeNode3
{
	int val;
	struct TreeNode3* left;
	struct TreeNode3* right;
};



void CreatBitTreeNode3(char str[][50], int return_count, TreeNode3* cur, int curIndex);
TreeNode3* CreatBitTree3(char str[][50], int return_count);
void get_path(char** array, struct TreeNode3* root, int* returnSize, int* buf, int local);
char** binaryTreePaths(struct TreeNode3* root, int* returnSize);
void free_tree3(TreeNode3* T);
