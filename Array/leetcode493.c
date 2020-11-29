/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-28 13:57:26
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//可能会超时（没想到提交的时候，是溢出！）
int reversePairs(int* nums, int numsSize) {
    int res = 0;
    if (numsSize < 2) {
        return 0;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] > 2147483647 * 0.5) {
                continue;
            } else if (nums[j] < -2147483647 * 0.5) {
                res++;
                continue;
            }
            if (nums[i] > 2 * nums[j]) {
                res++;
            }
        }
    }
    return res;
}
