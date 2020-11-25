/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-09 15:07:30
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* p = nums1 + m;
    memcpy(p, nums2, n * sizeof(int));
    qsort(nums1, nums1Size, sizeof(int), myCpr);
}
