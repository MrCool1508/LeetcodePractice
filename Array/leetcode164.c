/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-26 11:56:06
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), myCpr);
    int res = nums[1] - nums[0];
    for (int i = 0; i < numsSize - 1; i++) {
        if (res < nums[i + 1] - nums[i]) {
            res = nums[i + 1] - nums[i];
        }
    }
    return res;
}
