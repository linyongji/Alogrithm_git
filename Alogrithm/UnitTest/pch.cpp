// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"


//***************************************************************************************************//
//********读取ini文件函数，返回值为文件节的个数，入参为字符串数组的首地址，带回读取到的节名***************//
//***************************************************************************************************//

int CalcCount(int n, char(*str)[10],const char *FileName)
{
	TCHAR   chSectionNames[2048] = { 0 };//定义一个数组，保存读取节的名字
	char* pSectionName; //保存找到的某个节名字符串的首地址
	int i = 0;          //i指向数组chSectionNames的某个位置，从0开始，顺序后移
	int j = 0;      //j用来保存下一个节名字符串的首地址相对于当前i的位置偏移量
	int k = 0;      //临时变量，用于给str数组赋值
	int m = 0;      //临时变量，用于给str数组赋值
	int count = 0;      //统计节的个数    
	GetPrivateProfileSectionNames(chSectionNames, 2048, FileName);//获取文件中的节名，每个节名以"\0"分割，保存在chSectionNames中
																	   //要加头文件
	for (i = 0; i < 2048; i++, j++)//对chSectionName中保存的内容进行拆分
	{
		if (chSectionNames[0] == '\0')//如果第一个字符就是0，则说明ini中一个节也没有，
		{
			break;
		}
		if (chSectionNames[i] == '\0')
		{
			count++;
			pSectionName = &chSectionNames[i - j]; //找到一个0，则说明从这个字符往前，减掉j个偏移量，
												   //就是一个节名的首地址 
			j = -1;                               //找到一个节名后，j的值要还原，以统计下一个节名地址的偏移量
												  //赋成-1是因为节名字符串的最后一个字符0是终止符，不能作为节名
			for (m = 0; m <= strlen(pSectionName); m++)//把找到的节名保存到str中
			{
				str[k][m] = *(pSectionName + m);
			}
			k++;//变量自加，用来保存下一个节名
			//在获取节名的时候可以获取该节中键的值，前提是我们知道该节中有哪些键。
			if (chSectionNames[i + 1] == 0)
			{
				break;      //当两个相邻的字符都是0时，则所有的节名都已找到，循环终止
			}
		}
	}
	return count;//返回节名的个数
}


#if 1	
//***************************************************************************************************//
//************切割字符串函数，返回值为int数组的首地址，通过传入int指针带回数组元素个数***************//
//***************************************************************************************************//
int* str_device(CString str, int* value_count)
{
	char* token;	//存放被切割后的第一个子串
	static int Section_devide[500];//存放字符切割完成以后的数组元素值
	char Section_value[500] = { 0 };//存放nums转换成string类型的结果
	memset(Section_value, 0, sizeof(char) * 500);
	*value_count = 0;
	strcpy(Section_value, str);//将CString类型的字符串转换成char类型，方便后面切割字符串
	//获得切割到的第一个字符串
	token = strtok(Section_value, ",");
	/* 继续获取其他的子字符串 */
	while (token != NULL) {
		Section_devide[*value_count] = (_ttoi)(token);//把切割得到的子串转为int，存到数组中去。
		token = strtok(NULL, ",");
		(*value_count)++;		//记录存了多少个元素
	}
	return Section_devide;	//返回数组首地址
}
#endif
//字符串切割函数，返回值为切割后元素的个数，每个元素的类型为字符串型
int str_device2(CString str, char(*return_str)[50])
{
	int value_count = 0;
	char* token;	//存放被切割后的第一个子串
	char Section_value[500] = { 0 };//存放nums转换成string类型的结果
	memset(Section_value, 0, sizeof(char) * 500);
	strcpy(Section_value, str);//将CString类型的字符串转换成char类型，方便后面切割字符串
	//获得切割到的第一个字符串
	token = strtok(Section_value, ",");
	/* 继续获取其他的子字符串 */
	while (token != NULL) {
		strcpy(return_str[value_count], token);
		token = strtok(NULL, ",");
		value_count++;		//记录存了多少个元素
	}
	return value_count;	//返回数组首地址
}
int str_device3(CString str, char* *return_str)
{
	int value_count = 0;
	char* token;	//存放被切割后的第一个子串
	char Section_value[500] = { 0 };//存放nums转换成string类型的结果
	memset(Section_value, 0, sizeof(char) * 500);
	strcpy(Section_value, str);//将CString类型的字符串转换成char类型，方便后面切割字符串
	//获得切割到的第一个字符串
	token = strtok(Section_value, ",");
	/* 继续获取其他的子字符串 */
	while (token != NULL) {
		return_str[value_count] = (char*)malloc(sizeof(char) * 100);
		strcpy(return_str[value_count], token);
		token = strtok(NULL, ",");
		value_count++;		//记录存了多少个元素
	}
	return value_count;	//返回数组首地址
}
//字符串转bool
bool CstrToBool(CString str)
{
	if (str == "1") {
		return 1;
	}
	return 0;
}


