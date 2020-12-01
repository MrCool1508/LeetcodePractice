/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-01 11:01:37
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//下述方法，时间复杂度为O(n)
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res    = malloc(2 * sizeof(int));
    res[0]      = -1;
    res[1]      = -1;
    *returnSize = 2;
    if (numsSize < 1) {
        return res;
    } else if (1 == numsSize) {
        if (target == nums[0]) {
            res[0] = 0;
            res[1] = 0;
            return res;
        }
    } else {
        for (int i = 0; i < numsSize; i++) {
            if (target == nums[i]) {
                if (-1 == res[0]) {
                    res[0] = i;
                } else {
                    res[1] = i;
                }
            }
        }
        if (-1 == res[1] && -1 != res[0]) {
            res[1] = res[0];
        }
        return res;
    }
    return res;
}
