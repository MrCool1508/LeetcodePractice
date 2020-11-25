/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-27 11:44:24
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @name: 方法名称
 * @brief: 法一
 * @param {*}
 * @retval: none
 */
int minStartValue(int* nums, int numsSize) {
    int res       = 1;
    int cnt       = 1;
    int breakFlag = 0;    //中断计数标志位
    while (res >= 1) {
        for (int i = 0; i < numsSize; i++) {
            res += *(nums + i);
            if (res < 1) {
                breakFlag = 1;
                break;
            }
        }
        if (breakFlag == 1) {
            cnt++;
            res       = cnt;
            breakFlag = 0;
        } else {
            return cnt;
        }
    }
    return 0;
}
/**
 * @name: 方法名称
 * @brief: 法二
 * @param {*}
 * @retval: none
 */
int minStartValue(int* nums, int numsSize) {
    int sum, res;
    res = 1;
    sum = res;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum < 1) {
            res += 1 - sum;
            sum = 1;
        }
    }
    return res;
}
/**
 * @name: 方法名称
 * @brief: 法三
 * @param {*}
 * @retval: none
 */
int minStartValue(int* nums, int numsSize) {
    int sum, res;
    res     = 1;
    sum     = 0;
    int min = *nums;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum < min) {
            min = sum;
        }
    }
    if (min >= 1) {
        return 1;
    } else {
        return abs(min) + 1;
    }
}
