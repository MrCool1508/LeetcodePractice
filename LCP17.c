/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-17 10:56:31
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * @name: 方法名称
 * @brief: LCP17
 * @param {type}
 * @retval: none
 */
int calculate(char* s) {
    int res = 9;
    int x = 1, y = 0;         //初始x,y
    int s_len = strlen(s);    //计算A/B的个数
    for (int i = 0; i < s_len; i++) {
        if (s[i] == 'A') {
            x = 2 * x + y;
        } else {
            y = 2 * y + x;
        }
    }
    res = x + y;
    return res;
}
