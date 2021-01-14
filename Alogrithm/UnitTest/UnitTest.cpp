#include "pch.h"
#include "CppUnitTest.h"
#define FilePath "../Alogrithm/1_ContainsNearbyDuplicate.ini"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		

		TEST_METHOD(TestMethode1)
		{
			char str[50][10] = { 0 };//保存ini文件里  节的名字
			int count = CalcCount(50, str);//保存ini文件里 节的个数
			bool nReal;//保存运算结果
			CString na, nb, nExpect;	//b保存不同的键值
			for (int j = 0; j < count; j++)
			{
				GetPrivateProfileString(str[j], "na", " ", na.GetBuffer(20), 20, FilePath);
				GetPrivateProfileString(str[j], "nExpect", " ", nExpect.GetBuffer(20), 20, FilePath);
				nReal = add(_ttoi64(na), _ttoi64(nb));	//_ttoi是CString转为整型
				Assert::AreEqual(nReal, _ttoi64(nExpect));
			}

		}
	};
}
