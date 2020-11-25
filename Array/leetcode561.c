/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-19 13:29:20
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdlib.h>
#define MIN(x, y) (x > y) ? x : y;

//下述冒泡重排法超出时间限制
int* bubbleCompare(int* A, int ASize) {
    int* res = (int*)calloc(ASize, sizeof(int));
    int  temp;
    res = A;
    for (int i = 0; i < ASize - 1; i++) {
        for (int j = 0; j < ASize - 1 - i; j++) {
            if (*(res + j) > *(res + j + 1)) {
                temp           = *(res + j);
                *(res + j)     = *(res + j + 1);
                *(res + j + 1) = temp;
            }
        }
    }
    return res;
}

int myCmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int arrayPairSum(int* nums, int numsSize) {
    int i = 0, sum = 0;
    qsort(nums, numsSize, sizeof(int), myCmp);
    for (i = 0; i < numsSize; i = i + 2) {
        sum = sum + mymin(nums[i], nums[i + 1]);
    }
    return sum;
}

int arrayPairSum(int* nums, int numsSize) {
    int res = 0;
    //输入数字的数量为奇数
    int* resTemp = (int*)calloc(numsSize, sizeof(int));
    if (numsSize % 2 == 1) {
        return 0;
    } else {
        //先将其按照从小到大的顺序排列
        // resTemp = bubbleCompare(nums, numsSize);
        qsort(nums, numsSize, sizeof(int), myCmp);
        //每两个数取左边的值相加
        for (int i = 0; i < numsSize; i += 2) {
            res += *(nums + i);
        }
    }
    return res;
}
