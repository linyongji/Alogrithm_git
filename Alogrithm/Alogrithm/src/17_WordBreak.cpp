#include "../include/17_WordBreak.h"
//��Ŀ������һ���ǿ��ַ���s��һ�������ǿյ����б���ֵ�wordDict��
//      �ж�s�Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ���
//˼·�����ַ���s�ĵ�һ���ַ���ʼ����s��ǰword_len���ַ����ֵ��е�Ԫ�رȽϣ����ƥ�䵽��ͬ�ģ����Ӧ��ö��λ��1
//      ÿ��ö��λ��1ǰ�ȿ�����һλ�Ƿ�ΪҲΪ1�������Ϊ1����0��һֱ�����һ���ַ����������һ���ַ���ö��dp[s_len]
bool WordBreak(char* s, char** wordDict, int wordDictSize) {
    int s_len = strlen(s); // ��ȡs�ĳ���
    //�쳣����ж�
    if (wordDict == NULL || wordDictSize == 0 || s == NULL) {
        return false;
    }
    // ����һ��dp���飬��ʾ��ǰ�±�ʱǰ�����ĸ�Ƿ�������㱻���������������ʼ��Ϊfalse
    bool *dp = (bool *)malloc(sizeof(bool)*(s_len + 1));
    memset(dp, false, sizeof(bool) * (s_len + 1));
    dp[0] = true; // 0��Ҫ����ʼ��Ϊtrue

    // �ӵ�һ����ĸ��ʼ�������
    for (int i = 1; i <= s_len; i++) {
        // �ӵ�һ�����ʿ�ʼ����
        for (int j = 0; j < wordDictSize; j++) {
            // ��ȡ��ǰ�Ƚϵĵ��ʳ���
            int word_len = strlen(wordDict[j]);
            // s��ǰλ����ǰ��word_len��λ�ÿ�ʼ��worDict���бȽ��Ƿ����
            int k = i - word_len;   //kͬʱҲ��������dp[]����һ�ε�״̬
            // k < 0��ʾ�˹�ͷ�ˣ��϶�����������
            if (k < 0) {
                continue;
            }
            // �����ǰiλ�ú͵�ǰ�Ƚϵ�wordDict������ȣ���ôǰ����kλ��֮ǰҲҪ����������������ǰ��Ĳ����㣬��ʹ���ڴ�k~i����Ҳû����
            if (strncmp(s + k, wordDict[j], word_len) == 0) {
                dp[i] = (dp[k] && dp[0]);
            }
            // ���iλ�����������ˣ�����Ҫ�ٱȽϺ����worDict�ˣ�ֱ�ӱȽ���һ��i��λ�ü���
            if (dp[i] == 1) {
                break;
            }
        }
    }
    for (int t = 0; t < s_len; t++)
        printf("%d  ", dp[t]);
    // ����s���һ��λ���Ƿ������з���������
    return dp[s_len];

}
