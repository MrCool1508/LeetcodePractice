/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-10 18:32:01
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#define PAY 5
bool lemonadeChange(int* bills, int billsSize) {
    //排除特殊情况
    if (0 == billsSize) {
        return true;
    } else if (PAY != bills[0]) {
        return false;
    }

    int bill      = 0;
    int wallet[3] = {0};    //分别用于表示5/10/20的数量
    for (int i = 0; i < billsSize; i++) {
        bill = bills[i] - PAY;
        switch (bills[i]) {
            case 5:
                wallet[0]++;
                break;
            case 10:
                wallet[1]++;
                if (wallet[0]) {
                    wallet[0]--;
                } else {
                    return false;
                }
                break;
            case 20:
                wallet[2]++;
                if (wallet[0] <= 0) {
                    return false;
                } else {
                    if (wallet[1] <= 0) {
                        if (wallet[0] < 3) {
                            return false;
                        } else {
                            wallet[0] -= 3;
                        }
                    } else {
                        wallet[1]--;
                        wallet[0]--;
                    }
                }
                break;
            default:
                break;
        }
    }
    return true;
}
