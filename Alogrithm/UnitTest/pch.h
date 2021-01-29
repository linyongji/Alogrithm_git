// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
#include <atlstr.h>

#include"../Alogrithm/include/1_ContainsNearbyDuplicate.h"
#include"../Alogrithm/include/2_ExcelSheetColumnTitle.h"
#include"../Alogrithm/include/3_bool IsUgly.h"
#include"../Alogrithm/include/4_IsPalindrome.h"
#include"../Alogrithm/include/5_MinDepth.h"
#include"../Alogrithm/include/6_ContainsDuplicate.h"
#include"../Alogrithm/include/7_MaxDepth.h"
#include"../Alogrithm/include/8_HammingWeight.h"
#include"../Alogrithm/include/9_AddBinary.h"
#include"../Alogrithm/include/10_BinaryTreePaths.h"
#include"../Alogrithm/include/11_CanWinNim.h"
#include"../Alogrithm/include/12_IsValid.h"
#include"../Alogrithm/include/13_MyAtoi.h"
#include"../Alogrithm/include/14_SingleNumber.h"
#include"../Alogrithm/include/15_WordPattern.h"
#include"../Alogrithm/include/16_ReverseBits.h"
#include"../Alogrithm/include/17_WordBreak.h"
#include"../Alogrithm/include/18_PlusOne.h"
#include"../Alogrithm/include/19_MySqrt.h"
#include"../Alogrithm/include/20_MoveZeroes.h"
#include"../Alogrithm/include/21_Reverse.h"
#include"../Alogrithm/include/22_Rotate.h"



int CalcCount(int n, char(*str)[10],const char *FileName);
int* str_device(CString str, int* value_count);
int str_device2(CString str, char(*return_str)[50]);
int str_device3(CString str, char**return_str);
bool CstrToBool(CString str);


#endif //PCH_H
