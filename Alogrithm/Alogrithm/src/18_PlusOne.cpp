#include "../include/18_PlusOne.h"
//��Ŀ������һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//      ���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//      ����Լ���������� 0 ֮�⣬��������������㿪ͷ��
//˼·������Ӻ���ǰ���������Ϊ9�����λ��0��ǰһλ��1����Ϊ9�����λ��1������ԭ����
//      ������������磺9��99,999��9999�ȣ�����digitsSize+1���ռ䣬���λ��1������λ��0���������鳤��ΪdigitsSize+1
int* PlusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; --i) {//�Ӻ���ǰ��ʼ
        if (digits[i] == 9) {               //�ж��ǲ���9��
            digits[i] = 0;                  //��9����0
        }
        else {
            digits[i]++;                     //�������9����9��ǰһλ��1
            *returnSize = digitsSize;       //���鳤�Ȼ���ԭ����ĳ���
            return digits;                  //���ص�digits������Ҫ�ĵ�����
        }
    }
    //������������������㣬˵�����λ��λ�ˣ�����99,999,9999��
    int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));//����һ��int *������digitsSize+1���ռ�
    memset(result, 0, sizeof(int) * (digitsSize + 1));//������飬ÿһλ����0
    result[0] = 1;          //���λΪ1������λ����Ϊ0
    *returnSize = digitsSize + 1;//��������ĳ���Ϊԭ���鳤�ȼ�1
    return result;
}