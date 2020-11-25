/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-15 17:17:51
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * @name: numberOfSteps
 * @brief: leetcode1342
 * @param {type}
 * @retval: none
 */
int numberOfSteps(int num) {
    int res = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            num--;
        } else {
            num /= 2;
        }
        res++;
    }
    return res;
}
