/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-03 00:06:10
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
bool validMountainArray(int* A, int ASize) {
    if (ASize < 3) {
        return false;
    }
    bool res  = false;
    int  temp = 0;
    int* ptr  = A;
    for (int i = 0; i < ASize - 2; i++) {
        if (*ptr < *(ptr + 1)) {
            res = true;
        } else {
            res  = false;
            temp = i;
            break;
        }
        *ptr++;
    }
    printf("res:%d,temp:%d\r\n", (int)res, temp);

    if (res) {
        // } else if (res && temp) {
        if (*ptr > *(ptr + 1)) {
            return true;    //前ASize-1个数满足条件，且ASize-1>ASize
        } else {
            return false;    //单调递增，不满足
        }
    } else if (!temp) {
        return false;    //第一个数比第二个数大
    } else {
        for (int i = temp; i < ASize - 1; i++) {
            if (*ptr > *(ptr + 1)) {
                res = true;
            } else {
                res = false;
                break;
            }
            *ptr++;
        }
        return res;
    }
}
