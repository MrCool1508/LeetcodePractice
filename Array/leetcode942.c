/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-26 22:44:37
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int  s_len  = strlen(S);
    int  numLen = s_len + 1;
    int* res    = (int*)calloc(numLen, sizeof(int));
    int  numMax = s_len;    //因为数字从0开始
    *returnSize = numLen;
    return res;
}
