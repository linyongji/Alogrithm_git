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
#define FileName_11 "../Alogrithm/config/11_CanWinNim.ini"
#define FileName_12 "../Alogrithm/config/12_IsValid.ini"
#define FileName_13 "../Alogrithm/config/13_MyAtoi.ini"
#define FileName_14 "../Alogrithm/config/14_SingleNumber.ini"
#define FileName_15 "../Alogrithm/config/15_WordPattern.ini"
#define FileName_16 "../Alogrithm/config/16_ReverseBits.ini"
#define FileName_17 "../Alogrithm/config/17_WordBreak.ini"
#define FileName_18 "../Alogrithm/config/18_PlusOne.ini"
#define FileName_19 "../Alogrithm/config/19_MySqrt.ini"
#define FileName_20 "../Alogrithm/config/20_MoveZeroes.ini"
#define FileName_21 "../Alogrithm/config/21_Reverse.ini"
#define FileName_22 "../Alogrithm/config/22_Rotate.ini"
#define FileName_23 "../Alogrithm/config/23_RestoreIpAddresses.ini"




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
					Assert::AreEqual(nReal, nExpect);
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
	TEST_CLASS(UnitTest_11)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_11);
			CString input,output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", input.GetBuffer(20), 20, FileName_11);
				GetPrivateProfileString(Section_Name[i], "output", " ", output.GetBuffer(20), 20, FileName_11);
				bool nReal = CanWinNim(_ttoi(input));
				Assert::AreEqual(nReal, CstrToBool(output));
			}
		}
	};
	TEST_CLASS(UnitTest_12)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_12);
			char input_char[1024] = { 0 };
			CString input,output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", input.GetBuffer(200), 200, FileName_12);
				GetPrivateProfileString(Section_Name[i], "output", " ", output.GetBuffer(20), 20, FileName_12);
				strcpy(input_char, input);
				bool nReal = IsValid(input_char);
				Assert::AreEqual(nReal, CstrToBool(output));
			}
		}
	};
	TEST_CLASS(UnitTest_13)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_13);
			char input_char[1024] = { 0 };
			CString input, output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", input.GetBuffer(200), 200, FileName_13);
				GetPrivateProfileString(Section_Name[i], "output", " ", output.GetBuffer(20), 20, FileName_13);
				strcpy(input_char, input);
				int nReal = MyAtoi(input_char);
				Assert::AreEqual(nReal, _ttoi(output));
			}
		}
	};
	TEST_CLASS(UnitTest_14)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_14);
			int array_count = 0;
			int* Section_Value;
			CString input,output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "input", " ", input.GetBuffer(200), 200, FileName_14);
				GetPrivateProfileString(Section_Name[i], "output", " ", output.GetBuffer(20), 20, FileName_14);
				Section_Value = str_device(input, &array_count);
				int nReal = SingleNumber(Section_Value, array_count);
				Assert::AreEqual(nReal, _ttoi(output));
			}
		}
	};
	TEST_CLASS(UnitTest_15)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_15);
			char Pattern_char[1024] = { 0 };
			char Str_char[1024] = { 0 };
			CString Pattern, Str, Output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Pattern", " ", Pattern.GetBuffer(200), 200, FileName_15);
				GetPrivateProfileString(Section_Name[i], "Str", " ", Str.GetBuffer(400), 400, FileName_15);
				GetPrivateProfileString(Section_Name[i], "Output", " ", Output.GetBuffer(20), 20, FileName_15);
				strcpy(Pattern_char, Pattern);
				strcpy(Str_char, Str);
				bool nReal = WordPattern(Pattern_char, Str_char);
				Assert::AreEqual(nReal, CstrToBool(Output));
			}
		}
	};
	TEST_CLASS(UnitTest_16)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_16);
			CString input,output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input", " ", input.GetBuffer(200), 200, FileName_16);
				GetPrivateProfileString(Section_Name[i], "Output", " ", output.GetBuffer(200), 200, FileName_16);
				uint32_t nReal = ReverseBits((uint32_t)_atoi64(input));
				Assert::AreEqual(nReal, (uint32_t)_atoi64(output));
			}
		}
	};

	TEST_CLASS(UnitTest_17)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_17);
			CString Input1, Input2, Output;
			char Str_char[1024] = { 0 };
			char* WordDic[100];
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input1", " ", Input1.GetBuffer(200), 200, FileName_17);
				GetPrivateProfileString(Section_Name[i], "Input2", " ", Input2.GetBuffer(500), 500, FileName_17);
				GetPrivateProfileString(Section_Name[i], "Output", " ", Output.GetBuffer(20), 20, FileName_17);
				strcpy(Str_char, Input1);
				int Wordic_count = str_device3(Input2, WordDic);
				bool nReal = WordBreak(Str_char, WordDic, Wordic_count);
				Assert::AreEqual(nReal, CstrToBool(Output));
			}
		}
	};
	TEST_CLASS(UnitTest_18)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_18);
			int input_count = 0, output_count = 0, returnSize = 0;
			int* input_value;
			int* output_value;
			CString input,output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input", " ", input.GetBuffer(200), 200, FileName_18);
				GetPrivateProfileString(Section_Name[i], "Output", " ", output.GetBuffer(200), 200, FileName_18);
				input_value = str_device(input, &input_count);
				output_value = str_device(output, &output_count);
				int* nReal = PlusOne(input_value, input_count, &returnSize);
				for (int i = 0; i < input_count; i++) {
					Assert::AreEqual(nReal[i], output_value[i]);
				}
			}
		}
	};
	TEST_CLASS(UnitTest_19)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_19);
			CString input,output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input", " ", input.GetBuffer(100), 100, FileName_19);
				GetPrivateProfileString(Section_Name[i], "Output", " ", output.GetBuffer(100), 100, FileName_19);
				int nReal = MySqrt(_ttoi(input));
				Assert::AreEqual(nReal, _ttoi(output));
			}
		}
	};
	TEST_CLASS(UnitTest_20)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_20);
			int input_count = 0, output_count = 0, returnSize = 0;
			int* input_value;
			int* output_value;
			CString input, output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input", " ", input.GetBuffer(200), 200, FileName_20);
				GetPrivateProfileString(Section_Name[i], "Output", " ", output.GetBuffer(200), 200, FileName_20);
				input_value = str_device(input, &input_count);
				output_value = str_device(output, &output_count);
				MoveZeroes(input_value, input_count);
				for (int i = 0; i < input_count; i++) {
					Assert::AreEqual(input_value[i], output_value[i]);
				}
			}
		}
	};
	TEST_CLASS(UnitTest_21)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_21);
			CString input, output;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input", " ", input.GetBuffer(100), 100, FileName_21);
				GetPrivateProfileString(Section_Name[i], "Output", " ", output.GetBuffer(100), 100, FileName_21);
				int nReal = Reverse(_ttoi(input));
				Assert::AreEqual(nReal, _ttoi(output));
			}
		}
	};
	TEST_CLASS(UnitTest_22)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_22);
			int input_count = 0, output_count = 0, returnSize = 0;
			int* input_value;
			int* output_value;
			CString input, output,k;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input", " ", input.GetBuffer(200), 200, FileName_22);
				GetPrivateProfileString(Section_Name[i], "k", " ", k.GetBuffer(20), 20, FileName_22);
				GetPrivateProfileString(Section_Name[i], "Output", " ", output.GetBuffer(200), 200, FileName_22);
				input_value = str_device(input, &input_count);
				output_value = str_device(output, &output_count);
				 Rotate1(input_value, input_count, _ttoi(k));
				for (int i = 0; i < input_count; i++) {
					Assert::AreEqual(input_value[i], output_value[i]);
				}
			}
		}
	};
	TEST_CLASS(UnitTest_23)
	{
		TEST_METHOD(TestMethode1)
		{
			char Section_Name[100][10] = { 0 };
			int  Section_Count = CalcCount(100, Section_Name, FileName_23);
			CString Input, Output;
			char Str_char[20];
			char** return_char ;
			int return_len = 0;
			char output_char[100][50];
			int output_len = 0;
			for (int i = 0; i < Section_Count; i++) {
				GetPrivateProfileString(Section_Name[i], "Input", " ", Input.GetBuffer(20), 20, FileName_23);
				GetPrivateProfileString(Section_Name[i], "Output", " ", Output.GetBuffer(1024), 1024, FileName_23);
				output_len = str_device2(Output, output_char);
				strcpy(Str_char, Input);
				return_char = RestoreIpAddresses(Str_char, &return_len);
				Assert::AreEqual(return_len, output_len);		//先判断个数是否相等
				for (int j = 0; j < return_len; j++) {			//循环挨个比较
					Assert::AreEqual(return_char[j], output_char[j]);
				}
			}
		}
	};
}
