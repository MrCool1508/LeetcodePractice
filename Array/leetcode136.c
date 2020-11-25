/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-20 12:05:17
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdlib.h>
//方法一：暴力破解
int singleNumber(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }
    printf("nSize:%d\r\n", numsSize);
    int  numSum   = 0;
    int  tempSum  = 0;
    int  tempSize = (numsSize + 1) / 2;
    int* temp     = (int*)calloc(sizeof(int), tempSize);
    // temp[0]       = nums[0];

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                *temp = nums[i];
                tempSum += nums[i];
                *temp++;
                printf("!!!  %d|%d\r\n", i, j);
                break;
            }
        }
        numSum += nums[i];
    }
    numSum += nums[numsSize - 1];
    printf("ns:%d | ts:%d\r\n", numSum, tempSum);
    return numSum - 2 * tempSum;
}
//方法二：先排序，再用后一个值减前一个值
int myCmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int singleNumber(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), myCmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if ((nums[i + 1] - nums[i]) != 0) {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}
//方法三：异或

int singleNumber(int* nums, int numsSize) {
    int ans = nums[0];
    if (numsSize > 1) {
        for (int i = 1; i < numsSize; i++) {
            ans = ans ^ nums[i];
        }
    }
    return ans;
}
//递归型异或
int singleNumber(int* nums, int numsSize) {
    return numsSize == 1 ? nums[0] : (singleNumber(nums + 1, numsSize - 1) ^ nums[0]);
}
