#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define FileName_1  "../Alogrithm/config/1_ContainsNearbyDuplicate.ini"
#define FileName_2  "../Alogrithm/config/2_ExcelSheetColumnTiTle.ini"
#define FileName_3  "../Alogrithm/config/3_bool IsUgly.ini"
#define FileName_4  "../Alogrithm/config/4_IsPalindrome.ini"
#define FileName_6  "../Alogrithm/config/6_ContainsDuplicate.ini"

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
}
