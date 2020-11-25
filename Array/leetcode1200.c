/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-27 00:05:26
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/** 对returnColumnSizes的理解还不够
 * returnColumnSizes存储的是指针数组
 * *returnColumnSizes = (int*)calloc(sizeof(int), returnCnt);
 * 意味着动态分配returnCnt个指针数组，每个数组长度为1，存储着res每行元素的个数，一共有returnCnt行
 * (*returnColumnSizes)[j] = 2;所指向的数组长度都为2
 **/
int myCpr(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    int absTemp   = 0;
    int calNum    = arrSize - 1;
    int returnCnt = 0;
    qsort(arr, arrSize, sizeof(int), myCpr);    //从小到大排序
    int minTemp = abs(*arr - *(arr + 1));
    for (int i = 0; i < calNum; i++) {
        absTemp = abs(*(arr + i) - *(arr + i + 1));
        if (absTemp < minTemp) {
            minTemp   = absTemp;
            returnCnt = 1;
        } else if (absTemp == minTemp) {
            returnCnt++;
        }
    }
    *returnSize        = returnCnt;
    *returnColumnSizes = (int*)calloc(sizeof(int), returnCnt);
    int** res          = calloc(sizeof(int*), returnCnt);
    for (int i = 0, j = 0; i < calNum; i++) {
        absTemp = abs(*(arr + i) - *(arr + i + 1));
        if (absTemp == minTemp) {
            res[j]                  = (int*)calloc(sizeof(int), 2);
            (*returnColumnSizes)[j] = 2;
            res[j][0]               = *(arr + i);
            res[j][1]               = *(arr + i + 1);
            j++;
        }
    }
    return res;
}
