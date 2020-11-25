/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-17 10:45:11
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

0 <= i < j < k < arr.length;
| arr[i] - arr[j] | <= a;
| arr[j] - arr[k] | <= b;
| arr[i] - arr[k] | <= c;

/**
 * @name: 方法名称
 * @brief: leetcode1534
 * @param {type}
 * @retval: none
 */
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int res  = 0;
    int flag = 1;    // 0为不符合，1为符合
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            for (int k = j + 1; k < arrSize; k++) {
                flag = 1;
                if (abs(arr[i] - arr[j]) > a) {
                    flag = 0;
                }
                if (abs(arr[j] - arr[k]) > b) {
                    flag = 0;
                }
                if (abs(arr[i] - arr[k]) > c) {
                    flag = 0;
                }
                //               printf("%d| %d| %d!!!f:%d\r\n",arr[i],arr[j],arr[k],flag);
                if (flag) res++;
            }
        }
    }
    return res;
}
