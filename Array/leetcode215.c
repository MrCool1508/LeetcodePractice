/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-03 12:27:11
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int* myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), myCpr);
    return nums[numsSize - k];
}
