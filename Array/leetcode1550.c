/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 15:44:52
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
bool threeConsecutiveOdds(int* arr, int arrSize) {
    bool res = false;
    int* p   = arr;
    if (arrSize < 3) {
        return res;    //排除特殊情况
    }
    for (int i = 0; i <= arrSize - 3; i++) {
        if ((*p % 2) && (*(p + 1) % 2) && (*(p + 2) % 2)) {
            res = true;
            break;
        }
        *p++;
    }

    return res;
}
