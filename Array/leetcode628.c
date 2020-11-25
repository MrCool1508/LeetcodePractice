/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-09 14:00:24
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int maximumProduct(int* nums, int numsSize) {
    int res = 0;
    qsort(nums, numsSize, sizeof(int), myCpr);
    int* temp = (int*)calloc(4, sizeof(int));
    temp[0]   = nums[0] * nums[1] * nums[2];
    temp[1]   = nums[0] * nums[1] * nums[numsSize - 1];
    temp[2]   = nums[0] * nums[numsSize - 1] * nums[numsSize - 2];
    temp[3]   = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    qsort(temp, 4, sizeof(int), myCpr);
    res = temp[3];

    return res;
}
