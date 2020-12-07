/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-07 15:50:13
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int temp = x;
    int cnt  = 0;
    while (temp) {
        temp = temp / 10;
        cnt++;
    }
    int* temp_x  = calloc(cnt, sizeof(int));
    int  tempCnt = cnt;
    temp         = x;
    while (temp) {
        temp_x[tempCnt - 1] = temp % 10;
        tempCnt--;
    }
    int halfCnt = cnt / 2;
    for (int i = 0; i < halfCnt; i++) {
        if (temp_x[i] != temp_x[cnt - 1 - i]) {
            free(temp_x);
            return false;
        }
    }
    free(temp_x);
    return true;
}
//下述方法可能会造成溢出，因此需要对边界进行防范！
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int temp = x;
    int revX = 0;
    while (temp) {
        //其实还是不严谨，讨巧了。int的最大值是2147483647
        if (revX >= 214748365) {
            return false;
        }
        revX = 10 * revX + temp % 10;
        temp = temp / 10;
    }
    if (revX == x) {
        return true;
    } else {
        return false;
    }
}
