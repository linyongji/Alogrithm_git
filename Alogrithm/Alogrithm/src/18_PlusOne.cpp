#include "../include/18_PlusOne.h"
//题目：给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//      最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//      你可以假设除了整数 0 之外，这个整数不会以零开头。
//思路：数组从后往前遍历，如果为9，则该位置0，前一位加1；不为9，则该位加1，返回原数组
//      遇到特殊情况如：9，99,999，9999等，申请digitsSize+1个空间，最高位置1，其他位置0，返回数组长度为digitsSize+1
int* PlusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; --i) {//从后往前开始
        if (digits[i] == 9) {               //判断是不是9，
            digits[i] = 0;                  //是9，赋0
        }
        else {
            digits[i]++;                     //如果不是9，则9的前一位加1
            *returnSize = digitsSize;       //数组长度还是原数组的长度
            return digits;                  //返回的digits就是需要的的数组
        }
    }
    //如果上面条件都不满足，说明最高位进位了，比如99,999,9999等
    int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));//定义一个int *，分配digitsSize+1个空间
    memset(result, 0, sizeof(int) * (digitsSize + 1));//清空数组，每一位都置0
    result[0] = 1;          //最高位为1，其他位依旧为0
    *returnSize = digitsSize + 1;//返回数组的长度为原数组长度加1
    return result;
}