/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-19 16:47:40
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdbool.h>

int myCmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    bool res    = false;
    int  temp_1 = 0;
    int  temp_2 = 0;
    if (arrSize <= 2) {
        return true;
    }
    qsort(arr, arrSize, sizeof(int), myCmp);    //先从小到大排序
    for (int i = 1; i < arrSize - 1; i++) {
        temp_1 = arr[i] - arr[i - 1];    //第i项减第i-1项
        temp_2 = arr[i + 1] - arr[i];    //第i+1项减第i项
        if (temp_1 != temp_2) {
            res = false;
            return res;
        } else {
            res = true;
        }
    }
    return res;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    //排序并求出公差q
    qsort(arr, arrSize, sizeof(int), myCmp);
    int q = arr[1] - arr[0];
    //判断数组中的每个数字符不符合等差数列
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] != (arr[0] + q * i)) return false;
    }
    return true;
}
