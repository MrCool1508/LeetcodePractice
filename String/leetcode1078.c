/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-04 15:12:39
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>
#define MAX_WORD 500
char** findOcurrences(char* text, char* first, char* second, int* returnSize) {
    int textLen = strlen(text);
    if (0 == textLen) {
        return NULL;
    }
    //复制原始数据，避免strtok对外部数据造成影响
    char* textTemp = (char*)malloc((textLen + 1) * sizeof(text));
    memcpy(textTemp, text, textLen + 1);
    char**     text2word    = (char**)malloc(MAX_WORD * sizeof(char*));
    char**     text2wordPtr = text2word;
    char*      token;
    const char s[2] = " ";
    token           = strtok(textTemp, s);
    int wordCnt     = 0;
    //将原始数据放入text2word里。
    while (token != NULL) {
        *text2wordPtr = token;
        // printf("%s\r\n", *text2wordPtr);
        wordCnt++;
        *text2wordPtr++;
        token = strtok(NULL, s);
    }
    if (wordCnt <= 2) {
        return NULL;
    }
    //验证是否成功放入
    // for (int i = 0; i < wordCnt; i++) {
    //     printf("%s\r\n", text2word[i]);
    // }
    char** res    = (char**)malloc(wordCnt * sizeof(char*));
    char** resPtr = res;
    char*  strTemp;
    int    resCnt = 0;
    for (int i = 0; i < wordCnt - 2; i++) {
        if (0 == strcmp(first, text2word[i])) {
            if (0 == strcmp(second, text2word[i + 1])) {
                strTemp = (char*)malloc((strlen(text2word[i + 2]) + 1) * sizeof(char));
                strcpy(strTemp, text2word[i + 2]);
                // printf("%s\r\n",text2word[i+2]);
                *resPtr = strTemp;
                // printf("%s\r\n",*resPtr);
                *resPtr++;
                resCnt++;
            }
        }
    }

    *returnSize = resCnt;
    return res;
}
