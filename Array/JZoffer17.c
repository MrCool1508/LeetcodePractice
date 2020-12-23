/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-23 17:55:35
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//题目感觉有坑，可能会溢出
int* printNumbers(int n, int* returnSize) {
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        maxNum += 9 * pow(10, i);
    }
    *returnSize = maxNum;
    int* res    = malloc(maxNum * sizeof(int));
    for (int i = 0; i < maxNum; i++) {
        res[i] = i + 1;
    }
    return res;
}
//尝试优化
int* printNumbers(int n, int* returnSize) {
    int maxNum = 0;
    while (n) {
        maxNum = maxNum * 10 + 9;
        n--;
    }
    *returnSize = maxNum;
    int* res    = malloc(maxNum * sizeof(int));

    for (int i = 0; i < maxNum; i++) {
        res[i] = i + 1;
    }
    return res;
}
//再优化
int* printNumbers(int n, int* returnSize) {
    int maxNum  = pow(10, n) - 1;
    *returnSize = maxNum;
    int* res    = malloc(maxNum * sizeof(int));

    for (int i = 0; i < maxNum; i++) {
        res[i] = i + 1;
    }
    return res;
}
