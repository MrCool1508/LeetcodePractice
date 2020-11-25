/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-17 00:22:20
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * @name: 方法名称
 * @brief: leetcode1295
 * @param {type}
 * @retval: none
 */
int findNumbers(int* nums, int numsSize) {
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        cnt = 1;
        while ((*(nums + i) / 10) >= 1) {
            *(nums + i) /= 10;
            cnt++;
        }
        if (cnt % 2 == 0) {
            res++;
        }
    }
    return res;
}
