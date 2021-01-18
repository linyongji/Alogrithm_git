#include "../include/10_BinaryTreePaths.h"




int main()
{

	CString str = "3,9,20,NULL,NULL,15,17";
	CString str1 = "4,3,1,NULL,NULL,2,6,8";
	char return_str[100][50] = { 0 };
	int return_count = str_device2(str, return_str);
	TreeNode3* root = CreatBitTree3(return_str, return_count);
	int returnSize = 0;
	char** returnStr;
	char s[1024] = {0};
	char *q = "123";
	char* p = "123";
	returnStr = binaryTreePaths(root, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		 //sprintf(s, "%s", returnStr[i]);
		strcat(s, returnStr[i]);
		if (i != (returnSize-1))
		{
			s[strlen(s)] = ',';
		}
	}
	printf("%s\n", s);
	free_tree3(root);

	return 0;
}
