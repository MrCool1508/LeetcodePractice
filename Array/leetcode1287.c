/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-05 22:24:28
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <math.h>
//第一感觉用二分找会快一些，先暴力吧
int findSpecialInteger(int* arr, int arrSize) {
    int res        = 0;
    int tempCnt    = 0;
    int currentCnt = 0;
    int targetCnt  = arrSize / 4 + 1;
    int lastNum    = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == lastNum) {
            currentCnt++;
            lastNum = arr[i];
            tempCnt = fmax(tempCnt, currentCnt);
            if (tempCnt == currentCnt) {
                res = lastNum;
            }
        } else {
            currentCnt = 0;
            currentCnt++;
            lastNum = arr[i];
        }
        if (tempCnt >= targetCnt) {
            return res;
        }
    }
    return res;
}
//优化后的遍历
int findSpecialInteger(int* arr, int arrSize) {
    int targetCnt = arrSize / 4 + 1;
    for (int i = 0; i < arrSize - targetCnt + 1; i++) {
        if (arr[i] == arr[i + targetCnt - 1]) {
            return arr[i];
        }
    }
    return -1;
}

//二分试试,下述的二分，存在数组越界！先这样吧...
int lower_bound(int l, int r, int x, int* a) {
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}
int upper_bound(int l, int r, int x, int* a) {
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] <= x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}
int findSpecialInteger(int* arr, int arrSize) {
    int targetCnt = arrSize / 4 + 1;
    for (int i = 0; i < arrSize; i += targetCnt) {
        int x = lower_bound(arr[0], arr[arrSize - 1], arr[i], arr);
        int y = upper_bound(arr[0], arr[arrSize - 1], arr[i], arr);
        if (y - x >= targetCnt) {
            return arr[i];
        }
    }
    return arr[arrSize - 1];
}
