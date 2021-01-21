#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct compose {
	char ch;
	char* str;
}ComPose;

bool WordPattern(char* pattern, char* s);