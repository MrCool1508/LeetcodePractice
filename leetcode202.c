/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-29 21:18:04
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

int squareNum(int n) {
    int res     = 0;
    int lastRes = n;
    while (n) {
        res += (n % 10) * (n % 10);
        n /= 10;
        if (0 == n) {
            lastRes = res;
            if (1 == res) {
                return res;
            } else if (lastRes == res) {
                return 0;
            } else {
                n   = res;
                res = 0;
            }
        }
    }
}

bool isHappy(int n) {
    bool res = false;
    if (squareNum(n)) {
        return
    }
}
