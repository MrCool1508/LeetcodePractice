/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-21 16:07:41
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int rob(int* nums, int numsSize) {
    int res      = 0;
    int sum_odd  = 0;
    int sum_even = 0;
    int loopCnt  = numsSize / 2;
    if (numsSize == 0) {
        return 0;
    }

    if (numsSize % 2 == 1) {
        sum_odd += nums[numsSize - 1];
    }

    for (int i = 0; i < loopCnt; i++) {
        sum_odd += *(nums + 2 * i);
        sum_even += *(nums + 2 * i + 1);
    }
    sum_odd += nums[numsSize - 1];
    res = (sum_odd > sum_even) ? sum_odd : sum_even;

    return res;
}
