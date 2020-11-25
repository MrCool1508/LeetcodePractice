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
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** res          = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(sizeof(int));
    *returnSize        = numRows;
    //**returnColumnSizes = (int**)calloc(numRows, sizeof(int*));

    if (!numRows) {
        return res;
    }

    for (int i = 0; i < numRows; i++) {
        res[i]    = (int*)malloc((i + 1) * sizeof(int));
        res[i][0] = 1;
        res[i][i] = 1;
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            printf("eR:%d ", res[i][j]);
        }
        printf("\r\n");
    }
    for (int i = 0; i < numRows; i++) {
        returnColumnSizes[i][0] = i + 1;
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
