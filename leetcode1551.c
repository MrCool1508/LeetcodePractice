/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-16 17:32:15
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int minOperations(int n) {
    int res = 0;
    // bool oddFlag = false;
    // int  cnt     = n / 2;
    // int  temp    = n;    //最终的中值
    if ((n == 0) || (n == 1)) return 0;
    res = n * n / 4;
    // if (n % 2 == 1) oddFlag = true;    //奇数个元素

    return res;
}
