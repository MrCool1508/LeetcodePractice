/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-15 17:22:11
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
int sumArrayPos(int* arr, int arrLen, int pos, int n);
/**
 * @name: 方法名称
 * @brief: leetcode1588
 * @param {type}
 * @retval: none
 */
int sumOddLengthSubarrays(int* arr, int arrSize) {
    int sum         = 0;
    int cnt         = 0;
    int arrSizeTemp = arrSize;
    // int cntOdd      = 0;    //奇数
    // int cntEven     = 0;    //偶数

    //奇数写为2*cnt-1个sum，偶数写为2*cnt
    if (arrSizeTemp % 2 == 1) {
        arrSizeTemp++;
        while (arrSizeTemp > 0) {
            arrSizeTemp -= 2;
            cnt++;
        }
    } else {
        while (arrSizeTemp > 0) {
            arrSizeTemp -= 2;
            cnt++;
        }
    }
    // printf("cnt:%d\r\n",cnt);
    while (cnt >= 1) {
        sum += sumArrayPos(arr, arrSize, 0, (2 * cnt - 1));
        cnt--;
    }
    return sum;
}
/**
 * @name: sumArrayPos
 * @brief: 将指定字符串，从pos的位置(pos从0计)开始，
 *         连续取n个元素作为子串，将所有子串元素求和
 *         如["1,3,5,6,7,8"],pos=2,n=3,则子串为
 *         ["5,6,7"]，["6,7,8"],sum = 5+6+7+6+7+8
 * @param {type}
 * @retval: none
 */
int sumArrayPos(int* arr, int arrLen, int pos, int n) {
    int temp;
    int sum    = 0;
    int endPos = arrLen - n;    //也从0开始计
    for (int i = pos; i <= endPos; i++) {
        temp = n - 1;
        while (temp >= 0) {
            sum += arr[i + temp];
            temp--;
        }
        // printf("sum:%d\r\n",sum);
    }

    return sum;
}

int sumOddLengthSubarrays(int* arr, int arrSize) {
    int sum         = 0;
    int cnt         = 0;
    int endPos      = 0;    //也从0开始计
    int temp        = 0;
    int k           = 0;
    int arrSizeTemp = arrSize;
    // int cntOdd      = 0;    //奇数
    // int cntEven     = 0;    //偶数

    //奇数写为2*cnt-1个sum，偶数写为2*cnt
    if (arrSizeTemp % 2 == 1) {
        arrSizeTemp++;
        while (arrSizeTemp > 0) {
            arrSizeTemp -= 2;
            cnt++;
        }
    } else {
        while (arrSizeTemp > 0) {
            arrSizeTemp -= 2;
            cnt++;
        }
    }
    // printf("cnt:%d\r\n",cnt);

    while (cnt >= 1) {
        k      = 2 * cnt - 1;
        endPos = arrSize - k;
        for (int i = 0; i <= endPos; i++) {
            temp = k - 1;
            while (temp >= 0) {
                sum += arr[i + temp];
                temp--;
            }
            // printf("sum:%d\r\n",sum);
        }
        cnt--;
    }
    return sum;
}
