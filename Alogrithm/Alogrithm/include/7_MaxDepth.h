#pragma once
#include <stdio.h>
#include <math.h>
#include <atlstr.h>


struct TreeNode2
{
	int val;
	struct TreeNode2* left;
	struct TreeNode2* right;
};


int MaxDepth(struct TreeNode2* root);
TreeNode2* CreatBitTree2(char str[][50], int return_count);
void CreatBitTreeNode2(char str[][50], int return_count, TreeNode2* cur, int curIndex);
void free_tree2(TreeNode2* T);
