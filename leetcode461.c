/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-17 11:45:53
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int hammingDistance(int x, int y) {
    int res = 0;
    int temp_1, temp_2;
    temp_1 = temp_2 = x ^ y;

    while ((temp_1 / 2) >= 1) {
        temp_1 /= 2;
        printf("%d|%d\r\n", temp_2, temp_2 & 0x01);
        if ((temp_2 & 0x01) == 1) {
            res++;
        }
        temp_2 = temp_2 >> 1;
    }
    if (temp_2 == 1) res++;

    return res;
}
