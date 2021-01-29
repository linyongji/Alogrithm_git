#include "../include/17_WordBreak.h"
//题目：给定一个非空字符串s和一个包含非空单词列表的字典wordDict，
//      判定s是否可以被空格拆分为一个或多个在字典中出现的单词
//思路：从字符串s的第一个字符开始，拿s的前word_len个字符和字典中的元素比较，如果匹配到相同的，则对应的枚举位置1
//      每次枚举位置1前先考虑上一位是否为也为1，如果不为1就置0，一直到最后一个字符，返回最后一个字符的枚举dp[s_len]
bool WordBreak(char* s, char** wordDict, int wordDictSize) {
    int s_len = strlen(s); // 获取s的长度
    //异常情况判断
    if (wordDict == NULL || wordDictSize == 0 || s == NULL) {
        return false;
    }
    // 定义一个dp数组，表示当前下标时前面的字母是否可以满足被拆分条件，并都初始化为false
    bool *dp = (bool *)malloc(sizeof(bool)*(s_len + 1));
    memset(dp, false, sizeof(bool) * (s_len + 1));
    dp[0] = true; // 0需要被初始化为true

    // 从第一个字母开始往后遍历
    for (int i = 1; i <= s_len; i++) {
        // 从第一个单词开始遍历
        for (int j = 0; j < wordDictSize; j++) {
            // 获取当前比较的单词长度
            int word_len = strlen(wordDict[j]);
            // s当前位置往前退word_len个位置开始和worDict进行比较是否相等
            int k = i - word_len;   //k同时也用来访问dp[]的上一次的状态
            // k < 0表示退过头了，肯定不满足条件
            if (k < 0) {
                continue;
            }
            // 如果当前i位置和当前比较的wordDict正好相等，那么前提是k位置之前也要都满足条件，否则前面的不满足，即使现在从k~i满足也没有用
            if (strncmp(s + k, wordDict[j], word_len) == 0) {
                dp[i] = (dp[k] && dp[0]);
            }
            // 如果i位置满足条件了，则不需要再比较后面的worDict了，直接比较下一个i的位置即可
            if (dp[i] == 1) {
                break;
            }
        }
    }
    for (int t = 0; t < s_len; t++)
        printf("%d  ", dp[t]);
    // 返回s最后一个位置是否满足切分条件即可
    return dp[s_len];

}
