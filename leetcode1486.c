/*
 * @file: leetcode1486
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-12 11:14:40
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @name: xorOperation(int n, int start)
 * @brief: leetcode1486
 * @param {int n, int start}
 * @retval: int res
 */
int xorOperation(int n, int start) {
    //法一：但是有可能导致内存泄漏
    // int res = 0;
    // //创建nums数组
    // int* nums = (int*)malloc(sizeof(int) * n);
    // //将nums的值填入
    // for (int i = 0; i < n; i++) {
    //     *(nums + i) = start + 2 * i;
    //     res ^= *(nums + i);
    //     printf("%d | %d\r\n", *(nums + i), res);
    // }
    // //按位异或

    //法二
    int res = start;
    for (int i = 0; i < n - 1; i++) {
        start += 2;
        res ^= start;
        printf("%d | %d\r\n", start, res);
    }
    return res;
}
/**
 * @name: defangIPaddr(char* address)
 * @brief: leetcode1108
 * @param {char* address}
 * @retval: char*
 */
char* defangIPaddr(char* address) {
    //法一：暴力破解
    // int   originStrLen = strlen(address);    //获取原始字符串长度
    // int   afterStrLen  = originStrLen + 2 * 3 + 1;
    // char* res          = (char*)malloc(sizeof(char) * afterStrLen);
    // for (int i = 0, j = 0; i < originStrLen; i++, j++) {
    //     if (*(address + i) != '.') {
    //         *(res + j) = *(address + i);
    //     } else {
    //         *(res + j)     = '[';
    //         *(res + j + 1) = '.';
    //         *(res + j + 2) = ']';
    //         j += 2;
    //     }
    // }

    // *(res + afterStrLen - 1) = '\0';
    // return res;
    //法二：利用sscanf和sprintf格式化
    char* res = malloc(sizeof(char) * (strlen(address) + 2 * 3 + 1));
    int   add_1, add_2, add_3, add_4;
    sscanf(address, "%d.%d.%d.%d", &add_1, &add_2, &add_3, &add_4);
    sprintf(res, "%d[.]%d[.]%d[.]%d", add_1, add_2, add_3, add_4);
    printf("%s\r\n", res);
    return res;
}
/**
 * @name: 方法名称
 * @brief: leetcode807
 * @param {type}
 * @retval: none
 */
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {
    //先将二维方阵的每行、每列最大值找到，得到天际线数组
    //天际线数组作为增长边界，将原方阵元素值变大
    //每个数字累加减去原方阵的数字累加
    int  res       = 0;
    int  sumBefore = 0;
    int  sumAfter  = 0;
    int  bound     = 0;
    int  rowLen    = gridSize;
    int  colLen    = gridColSize[0];
    int* maxRow    = (int*)malloc(sizeof(int) * rowLen);
    int* maxCol    = (int*)malloc(sizeof(int) * colLen);
    // gridSize为行数,gridColSize为列数
    for (int i = 0; i < rowLen; i++) {
        for (int j = 0; j < colLen; j++) {
            maxRow[i] = (grid[i][j] > maxRow[i]) ? (grid[i][j]) : (maxRow[i]);
            maxCol[j] = (grid[i][j] > maxCol[j]) ? (grid[i][j]) : (maxCol[j]);
            sumBefore += grid[i][j];
            printf("%d ", grid[i][j]);
        }
        printf("\r\n");
    }
    for (int i = 0; i < rowLen; i++) {
        for (int j = 0; j < colLen; j++) {
            sumAfter += (maxCol[j] > maxRow[i]) ? (maxRow[i]) : (maxCol[j]);
        }
    }
    free(maxRow);
    free(maxCol);
    res = sumAfter - sumBefore;
    return res;
}

int getMinimumDifference(struct TreeNode* root) {
    int res = 0;
    return res;
}

// int main(int argc, char const* argv[]) {
//     system("pause");
//     return 0;
// }
