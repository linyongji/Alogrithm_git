#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define FileName_1  "../Alogrithm/config/1_ContainsNearbyDuplicate.ini"
#define FileName_2  "../Alogrithm/config/2_ExcelSheetColumnTiTle.ini"
#define FileName_3  "../Alogrithm/config/3_bool IsUgly.ini"
#define FileName_4  "../Alogrithm/config/4_IsPalindrome.ini"
#define FileName_5  "../Alogrithm/config/5_MinDepth.ini"
#define FileName_6  "../Alogrithm/config/6_ContainsDuplicate.ini"
#define FileName_7  "../Alogrithm/config/7_MaxDepth.ini"
#define FileName_8  "../Alogrithm/config/8_HammingWeight.ini"
#define FileName_9  "../Alogrithm/config/9_AddBinary.ini"
#define FileName_10 "../Alogrithm/config/10_BinaryTreePaths.ini"


namespace UnitTest
{
	TEST_CLASS(UnitTest_1)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_1);
			int array_count = 0;
			int* Section_Value;
			CString Na, Nb, nExpect;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "array", " ", Na.GetBuffer(200), 200, FileName_1);
				GetPrivateProfileString(Section_Name[i], "key", " ", Nb.GetBuffer(20), 20, FileName_1);
				GetPrivateProfileString(Section_Name[i], "output", " ", nExpect.GetBuffer(20), 20, FileName_1);
				Section_Value = str_device(Na, &array_count);
				bool nReal = ContainsNearbyDuplicate(Section_Value, array_count, _ttoi(Nb));
				Assert::AreEqual(nReal, CstrToBool(nExpect));
			}
		}
	};
	TEST_CLASS(UnitTest_2)
		{
			TEST_METHOD(TestMethode1)
			{
				char Section_Name[100][10] = { 0 };
				int  Section_Count = CalcCount(100, Section_Name, FileName_2);
				CString Na, nExpect;
				for (int i = 0; i < Section_Count; i++) {
					GetPrivateProfileString(Section_Name[i], "Na", " ", Na.GetBuffer(20), 20, FileName_2);
					GetPrivateProfileString(Section_Name[i], "nExpect", " ", nExpect.GetBuffer(100), 100, FileName_2);
					char* nReal = ExcelSheetColumnTitle(_ttoi(Na));
					Assert::AreEqual(*nReal, *nExpect);
				}
			}
	};
	TEST_CLASS(UnitTest_3)
		{
			TEST_METHOD(TestMethode3)
			{
				char Section_Name[100][10] = { 0 };
				int  Section_Count = CalcCount(100, Section_Name, FileName_3);
				CString Na, nExpect;
				for (int i = 0; i < Section_Count; i++) {
					GetPrivateProfileString(Section_Name[i], "Na", " ", Na.GetBuffer(20), 20, FileName_3);
					GetPrivateProfileString(Section_Name[i], "nExpect", " ", nExpect.GetBuffer(20), 20, FileName_3);
					bool nReal = IsUgly(_ttoi(Na));
					Assert::AreEqual(nReal, CstrToBool(nExpect));
				}
			}
	};
	TEST_CLASS(UnitTest_4)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_4);
			CString Na, nExpect;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Na", " ", Na.GetBuffer(20), 20, FileName_4);
				GetPrivateProfileString(Section_Name[i], "nExpect", " ", nExpect.GetBuffer(20), 20, FileName_4);
				bool nReal = IsPalindrome(_ttoi(Na));
				Assert::AreEqual(nReal, CstrToBool(nExpect));
			}
		}
	};
	TEST_CLASS(UnitTest_5)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_5);
			CString Na, nExpect;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", Na.GetBuffer(200), 200, FileName_5);
				GetPrivateProfileString(Section_Name[i], "output", " ", nExpect.GetBuffer(20), 20, FileName_5);
				char return_str[100][50] = { 0 };
				int return_count = str_device2(Na, return_str);
				TreeNode* root = CreatBitTree(return_str, return_count);
				int nReal = MinDepth(root);
				Assert::AreEqual(nReal,_ttoi(nExpect));
				free_tree(root);
			}
		}
	};
	TEST_CLASS(UnitTest_6)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_6);
			int array_count = 0;
			int* Section_Value;
			CString Na, Nb, nExpect;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", Na.GetBuffer(200), 200, FileName_6);
				GetPrivateProfileString(Section_Name[i], "output", " ", nExpect.GetBuffer(20), 20, FileName_6);
				Section_Value = str_device(Na, &array_count);
				bool nReal = containsDuplicate(Section_Value, array_count);
				Assert::AreEqual(nReal, CstrToBool(nExpect));
			}
		}
	};
	TEST_CLASS(UnitTest_7)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_7);
			CString Na, nExpect;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", Na.GetBuffer(200), 200, FileName_7);
				GetPrivateProfileString(Section_Name[i], "output", " ", nExpect.GetBuffer(20), 20, FileName_7);
				char return_str[100][50] = { 0 };
				int return_count = str_device2(Na, return_str);
				TreeNode2* root = CreatBitTree2(return_str, return_count);
				int nReal = MaxDepth(root);
				Assert::AreEqual(nReal, _ttoi(nExpect));
				free_tree2(root);
			}
		}
	};
	TEST_CLASS(UnitTest_8)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_8);
			CString Na, nExpect;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", Na.GetBuffer(20), 20, FileName_8);
				GetPrivateProfileString(Section_Name[i], "output", " ", nExpect.GetBuffer(100), 100, FileName_8);
				int nReal = HammingWeight(_ttoi(Na));
				Assert::AreEqual(nReal, _ttoi(nExpect));
			}
		}
	};
	TEST_CLASS(UnitTest_9)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_9);
			CString input1,input2, output;	
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input1", " ", input1.GetBuffer(100), 100, FileName_9);
				GetPrivateProfileString(Section_Name[i], "input2", " ", input2.GetBuffer(100), 100, FileName_9);
				GetPrivateProfileString(Section_Name[i], "output", " ", output.GetBuffer(200), 200, FileName_9);
				char p1[100];
				char p2[100];
				strcpy(p1, input1);
				strcpy(p2, input2);
				char* nReal = AddBinary(p1,p2);
				Assert::AreEqual(nReal, output);
			}
		}
	};
	TEST_CLASS(UnitTest_10)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_10);
			CString Na, nExpect;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", Na.GetBuffer(200), 200, FileName_10);
				GetPrivateProfileString(Section_Name[i], "output", " ", nExpect.GetBuffer(500), 500, FileName_10);
				char return_str[100][50] = { 0 };
				int return_count = str_device2(Na, return_str);
				TreeNode3* root = CreatBitTree3(return_str, return_count);
				int returnSize = 0;
				char** returnStr=NULL;
				returnStr = binaryTreePaths(root, &returnSize);
				char nReal[500] = { 0 };
				for (int i = 0; i < returnSize; i++)
				{
					strcat(nReal, returnStr[i]);
					if (i != (returnSize - 1))
					{
						nReal[strlen(nReal)] = ',';
					}
				}

				Assert::AreEqual(nReal,nExpect);
				free_tree3(root);
			}
		}
	};
}
