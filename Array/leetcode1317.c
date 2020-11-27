/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-27 09:13:40
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//感觉像是一个振荡器
/**
 * @name: checkZero(int a)
 * @brief: 用于检查该数是否有0
 * @param {*}
 * @retval: none
 */
int checkZero(int a) {
    while (a) {
        if (0 == a % 10) {
            return 0;    //含有0
        } else {
            a /= 10;
        }
    }
    return 1;    //不含0
}
int* getNoZeroIntegers(int n, int* returnSize) {
    int* res    = calloc(2, sizeof(int));
    *returnSize = 2;
    for (int i = 1; i < n; i++) {
        if (checkZero(i) && checkZero(n - i)) {
            res[0] = i;
            res[1] = n - i;
            break;
        }
    }
    return res;
}
