/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-14 16:00:44
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * 输入：字符串（相当于是二维数组），字符串的大小
 * 输出：检索后的字符串以及字符串的大小，字符串可以用sprintf进行格式化
 * 算法分析：
 * 1）根据字符串大小，遍历逗号数量n，则子字符串的数量为n+1
 * 2）创建n+1个表
 */
struct strList {
    char* strOrigin;
    int   charLen;
};
/**
 * @name: commonChars
 * @brief: 方法功能描述
 * @param {char** A： 字符串A
 *         int ASize： 子字符串的数量
 *         int* returnSize： 返回字符串的大小}
 * @retval: none
 */

char** commonChars(char** A, int ASize, int* returnSize) {
    int ptrCnt   = 0;        //指针计数
    int lastI    = 0;        //上一次出现逗号的位置
    int commaCnt = 0;        //逗号的数量
    int strCnt   = ASize;    //子字符串的数量

    //记录每个字符串的长度
    int* strPos = (int*)calloc(strCnt, sizeof(int));
    for (int i = 0; i < strCnt; i++) {
        strPos[i] = strlen(*(A + i));
    }

    //找出最短字符串的长度，及所在的位置
    int minLen    = strPos[0];    //最短字符串的长度，不含'\0'
    int minLenPos = 0;            //记录最短字符串的位置

    for (int i = 0; i < strCnt; i++) {
        if (minLen > strPos[i]) {
            minLen    = strPos[i];    //找到最短字符串的长度
            minLenPos = i;            //最短字符串长度所在的位置
        }
    }
    char* minStr = calloc((minLen + 1), sizeof(char));    //存储最短字符串
    strcpy(minStr, *(A + minLenPos));                     //将最短的字符串取出放入minStr
    //将最短字符串每一字符与其他字符串的每一字符作比较
    int* compareRes = (int*)calloc(minLen, sizeof(int));
    int* minRes     = (int*)calloc(minLen, sizeof(int));    //最短字符串的字符在各个字符串中出现的最小次数，包含本身
    for (int i = 0; i < minLen; i++) {
        for (int j = 0; j < strCnt; j++) {
            compareRes[i] = 0;
            for (int k = 0; k < strPos[j]; k++) {
                if (A[j][k] == minStr[i]) {
                    compareRes[i] += 1;
                }
            }
            if (j == 0) {
                minRes[i] = compareRes[i];    //将第一次取出的值放入minRes
            } else if (compareRes[i] < minRes[i]) {
                minRes[i] = compareRes[i];
            }
        }
    }
    free(compareRes);
    //检查最短字符串是否有重复的字母
    for (int i = 0; i < minLen; i++) {
        for (int j = i + 1; j < minLen; j++) {
            if (minStr[i] == minStr[j]) {
                minRes[j] = 0;
            }
        }
    }
    free(minStr);
    //判断统计值中非0的字母个数
    int noneZeroCnt = 0;
    int resSize     = 0;
    for (int i = 0; i < minLen; i++) {
        if (minRes[i] != 0) {
            noneZeroCnt++;
            resSize += minRes[i];
        }
    }
    // printf("noneZeroCnt:%d | resSize:%d\r\n", noneZeroCnt, resSize);
    char** res     = (char**)calloc(resSize * 2, sizeof(char*));
    char** resTemp = res;
    // printf("%d\r\n",res);
    for (int i = 0; i < minLen; i++) {
        while (minRes[i] > 0) {
            // printf("minRes:%d\r\n",minRes[i]);
            *resTemp      = (char*)calloc(2, sizeof(char));
            (*resTemp)[0] = A[minLenPos][i];
            (*resTemp)[1] = '\0';
            resTemp++;
            minRes[i]--;
        }
    }

    *returnSize = resSize;
    free(strPos);
    free(minRes);
    return res;
}

// int main(int argc, char const* argv[]) {
//     //    char** A = {"bella", "label", "roller"};
//     //    int*   returnNum;
//     //    commonChars(A, 3, returnNum);
//     system("pause");
//     return 0;
// }
