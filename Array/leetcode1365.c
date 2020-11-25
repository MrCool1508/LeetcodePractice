/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-16 17:22:10
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @name: 方法名称
 * @brief: leetcode1365
 * @param {type}
 * @retval: none
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                res[i]++;
            } else if (nums[i] < nums[j]) {
                res[j]++;
            }
        }
    }

    *returnSize = numsSize;
    return res;
}
