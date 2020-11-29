/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-29 12:03:21
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * 初步想法：
 * 1、qsort
 * 2、从最大的数开始取
 * 3、通过两边之和大于第三边的要求剔除不符合的数
 **/
/**
 * 第一版想复杂了，三边比较全部计算一次，忽略了
 * qsort之后，有序的三个数只用比较一次即可。
 * 看了题解，这种方式为贪心法。
 **/
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int largestPerimeter(int* A, int ASize) {
    int res = 0;
    qsort(A, ASize, sizeof(int), myCpr);
    for (int i = ASize - 1; i >= 2; i--) {
        if (A[i - 2] + A[i - 1] > A[i]) {
            res = A[i - 2] + A[i - 1] + A[i];
            return res;
        }
    }
    return res;
}
