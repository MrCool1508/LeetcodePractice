/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 20:26:56
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * 下述方法超时啦！
 * */
// bool checkPerfectNumber(int num) {
//     bool res = false;
//     int  sum = 0;
//     //先找出所有正因子
//     //并求和
//     for (int i = 1; i < num; i++) {
//         if (!(num % i)) {
//             sum += i;
//         }
//     }
//     if (sum == num) {
//         res = true;
//     }

//     return res;
// }

bool checkPerfectNumber(int num) {
    bool res = false;
    int  sum = 0;

    for (int i = 1; i * i < num; i++) {
        if (!(num % i)) {
            sum += i;
            if (i != 1) {
                sum += num / i;
            }
            if (sum > num) {
                res = false;
                break;
            }
        }
    }
    if (sum == num) {
        res = true;
    }

    return res;
}
