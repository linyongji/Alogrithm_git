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
			char str[50][10] = { 0 };//����ini�ļ���  �ڵ�����
			int count = CalcCount(50, str);//����ini�ļ��� �ڵĸ���
			bool nReal;//����������
			CString na, nb, nExpect;	//b���治ͬ�ļ�ֵ
			for (int j = 0; j < count; j++)
			{
				GetPrivateProfileString(str[j], "na", " ", na.GetBuffer(20), 20, FilePath);
				GetPrivateProfileString(str[j], "nExpect", " ", nExpect.GetBuffer(20), 20, FilePath);
				nReal = add(_ttoi64(na), _ttoi64(nb));	//_ttoi��CStringתΪ����
				Assert::AreEqual(nReal, _ttoi64(nExpect));
			}

		}
	};
}
