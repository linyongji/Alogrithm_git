#pragma once
#include <string.h>
#include <stdlib.h>
char** RestoreIpAddresses(char* s, int* returnSize);
void dfs(char* s, int s_len, char** returnStr, int* returnSize, int step, int index, char* temp);