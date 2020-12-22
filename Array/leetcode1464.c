/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-22 21:42:41
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int maxProduct(int* nums, int numsSize) {
    int res = 0;
    qsort(nums, numsSize, sizeof(int), myCpr);
    res = (nums[numsSize - 1] - 1) * (nums[numsSize - 2] - 1);
    return res;
}
