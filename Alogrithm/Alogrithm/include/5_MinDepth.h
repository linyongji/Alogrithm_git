#pragma once
#include <stdio.h>
#include <math.h>
#include <atlstr.h>


struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};


int MinDepth(struct TreeNode* root);
TreeNode* CreatBitTree(char str[][50], int return_count);
void CreatBitTreeNode1(char str[][50], int return_count, TreeNode* cur, int curIndex);
void free_tree(TreeNode* T);
