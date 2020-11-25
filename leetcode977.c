/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-16 10:49:38
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @name: 方法名称
 * @brief: leetcode977.冒泡法，超时
 * @param {type}
 * @retval: none
 */
int* sortedSquares(int* A, int ASize, int* returnSize) {
    int* res = (int*)calloc(ASize, sizeof(int));
    int* ptr = res;
    int  minTemp;

    for (int i = 0; i < ASize; i++) {
        *(res + i) = *(A + i) * (*(A + i));
    }
    for (int i = 0; i < ASize - 1; i++) {
        for (int j = 0; j < ASize - 1 - i; j++) {
            if (*(res + j) > *(res + j + 1)) {
                minTemp        = *(res + j);
                *(res + j)     = *(res + j + 1);
                *(res + j + 1) = minTemp;
            }
        }
    }
    *returnSize = ASize;
    return res;
}
/**
 * @name: 方法名称
 * @brief: 冒泡法
 * @param {type}
 * @retval: none
 */
int* bubbleCompare(int* A, int ASize) {
    int* res = (int*)calloc(ASize, sizeof(int));
    int  temp;

    for (int i = 0; i < ASize - 1; i++) {
        for (int j = 0; j < ASize - 1 - i; j++) {
            if (*(res + j) > *(res + j + 1)) {
                temp           = *(res + j);
                *(res + j)     = *(res + j + 1);
                *(res + j + 1) = temp;
            }
        }
    }
    return res;
}
int* sortedSquares(int* A, int ASize, int* returnSize) {
    int* res    = (int*)calloc(ASize, sizeof(int));
    int  middle = ASize / 2;    //从0开始计位置
    *(res + ASize-1) = ((*(A + ASize-1) ^ 2 > (*A) ^ 2)) ? ((*(A + ASize-1) ^ 2) : ((*A) ^ 2);//两边必然有最大
    if (ASize % 2) {

        
    } else {

    }

    *returnSize = ASize;
    return res;
}

int main(int argc, char const* argv[]) {
    int  Size = 5;
    int* A    = {16, 1, 0, 9, 100};

    bubbleCompare(A, Size);
    system("pause");
    return 0;
}
