/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-30 14:04:44
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

#include "uthash.h"
/**
 * 这道题只想到了将S中每个字母出现的次数进行统计，
 * 后续的操作没什么思路。因此参考了官网题解：
 * “如果出现次数最多的字母可以在重新排布之后不相邻，
 * 则可以重新排布字母使得相邻的字母都不相同。
 * 如果出现次数最多的字母过多，则无法重新排布字母使得相邻的字母都不相同。
 * 假设字符串的长度为 n，如果可以重新排布成相邻的字母都不相同的字符串，每个字母最多出现多少次？
 * 当 n 是偶数时，有 n/2个偶数下标和 n/2个奇数下标。
 * 因此每个字母的出现次数都不能超过 n/2 次，否则出现次数最多的字母一定会出现相邻。（！重点！）
 * 当 n 是奇数时，由于共有 (n+1)/2 个偶数下标。
 * 因此每个字母的出现次数都不能超过(n+1)/2 次，否则出现次数最多的字母一定会出现相邻。
 * 由于当 n 是偶数时，在整数除法下满足 n/2和 (n+1)/2 相等。
 * 因此可以合并 n 是偶数与 n 是奇数的情况：
 * 如果可以重新排布成相邻的字母都不相同的字符串，每个字母最多出现(n+1)/2 次。
 * 因此首先遍历字符串并统计每个字母的出现次数，
 * 如果存在一个字母的出现次数大于(n+1)/2，则无法重新排布字母使得相邻的字母都不相同，返回空字符串。
 * 如果所有字母的出现次数都不超过 (n+1)/2，则考虑如何重新排布字母。
”
 *
 */

char* reorganizeString(char* S) {
    int S_len = strlen(S);
    // printf("------>len:%d\r\n",S_len);
    if (S_len <= 2) {
        return S;
    }

    int* alphaDic = calloc(26, sizeof(int));    //存储26个字母出现的次数
    int  maxCnt   = 0;
    for (int i = 0; i < S_len; i++) {
        alphaDic[S[i] - 'a']++;
        maxCnt = fmax(maxCnt, alphaDic[S[i] - 'a']);
    }
    if (maxCnt > (S_len + 1) / 2) {
        return "";
    }

    char* res   = (char*)malloc((S_len + 1) * sizeof(char));
    res[S_len]  = '\0';
    int halfLen = S_len / 2;
    int evenIdx = 0, oddIdx = 1;    //奇数偶数的位置
    for (int i = 0; i < 26; i++) {
        //首先要求原字符串存在的字符
        //其次要求小于halfLen
        //（验证了，必须有，该条件，不然会将超出halfLen的数安排在奇数位，奇数位不足时，将安排至0位从而相邻）
        //最后要求奇数位置的长度应小于最大长度（否则会溢出）
        while (alphaDic[i] > 0 && alphaDic[i] <= halfLen && oddIdx < S_len) {
            res[oddIdx] = 'a' + i;
            // printf("res[%d]:%c,oId:%d\r\n", i, res[oddIdx], oddIdx);
            alphaDic[i]--;
            oddIdx += 2;
        }
        while (alphaDic[i] > 0) {
            res[evenIdx] = 'a' + i;
            // printf("res[%d]:%c,eId:%d\r\n", i, res[evenIdx], evenIdx);
            alphaDic[i]--;
            evenIdx += 2;
        }
    }
    return res;
}

char* reorganizeString(char* S) {
    int n = strlen(S);
    if (n < 2) {
        return S;
    }
    int counts[26];
    memset(counts, 0, sizeof(counts));
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        char c = S[i];
        counts[c - 'a']++;
        maxCount = fmax(maxCount, counts[c - 'a']);
    }
    if (maxCount > (n + 1) / 2) {
        return "";
    }
    char* reorganizeArray = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        reorganizeArray[i] = ' ';
    }
    reorganizeArray[n] = '\0';
    int evenIndex = 0, oddIndex = 1;
    int halfLength = n / 2;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < n) {
            reorganizeArray[oddIndex] = c;
            counts[i]--;
            oddIndex += 2;
        }
        while (counts[i] > 0) {
            reorganizeArray[evenIndex] = c;
            counts[i]--;
            evenIndex += 2;
        }
    }
    return reorganizeArray;
}
