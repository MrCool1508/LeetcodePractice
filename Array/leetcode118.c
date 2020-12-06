/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 20:47:30
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** res          = (int**)calloc(numRows, sizeof(int*));
    *returnColumnSizes = (int*)calloc(numRows, sizeof(int));
    *returnSize        = numRows;
    //**returnColumnSizes = (int**)calloc(numRows, sizeof(int*));

    if (!numRows) {
        return res;
    }

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        res[i]                  = (int*)calloc((i + 1), sizeof(int));
        res[i][0]               = 1;
        res[i][i]               = 1;
        // printf("%3d ", res[i][0]);
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            // printf("%3d ", res[i][j]);
        }
        if (i != 0) {
            // printf("%3d ", res[i][i]);
        }

        // printf("\r\n");
    }
    return res;
}

// int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
//     int** result       = (int**)malloc(sizeof(int*) * numRows);
//     *returnSize        = numRows;                                //返回的行数
//     *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);    //用来储存每一行的大小

//     for (int i = 0; i < numRows; i++) {
//         (*returnColumnSizes)[i] = i + 1;    //注意此处一定要写成带括号的
//         result[i]               = (int*)malloc(sizeof(int) * (i + 1));
//         result[i][0]            = 1;
//         for (int j = i - 1; j > 0; j--) {
//             result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
//         }
//         result[i][i] = 1;
//     }

//     return result;
// }

int main(int argc, char const* argv[]) {
    int** res = (int**)malloc(sizeof(int*) * 10);
    int*  returnSize;
    int** returnColumnSizes;
    res = generate(10, returnSize, returnColumnSizes);
    return 0;
}
