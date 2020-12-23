/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-23 18:15:56
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//每两个数字之后，看第三位为数字 or #。
char* freqAlphabets(char* s) {
    int   s_len = strlen(s);
    char* res   = (char*)malloc(1000 * sizeof(char));
    if (s_len < 3) {
        for (int i = 0; i < s_len; i++) {
            res[i] = s[i] - '1' + 'a';
        }
        res[s_len] = '\0';
        return res;
    }
    int cnt = 0;
    int j   = 0;
    //从前往后会有特殊情况，从后往前应该可以避免
    for (int i = 0; i < s_len - 2;) {
        printf("%c\r\n", s[i + 2]);
        if (s[i + 2] == '#') {
            res[cnt++] = (s[i] - '1' + 1) * 10 + s[i + 1] - '0' - 10 + 'j';
            i += 3;
        } else {
            res[cnt++] = s[i] - '1' + 'a';
            i++;
        }
    }
    res[cnt++] = s[s_len - 2] - '1' + 'a';
    res[cnt++] = s[s_len - 1] - '1' + 'a';
    res[cnt]   = '\0';
    return res;
}
//重新处理一下，从后往前
char* freqAlphabets(char* s) {
    int   s_len = strlen(s);
    char* res   = (char*)malloc(1000 * sizeof(char));
    if (s_len < 3) {
        for (int i = 0; i < s_len; i++) {
            res[i] = s[i] - '1' + 'a';
        }
        res[s_len] = '\0';
        return res;
    }
    int cnt  = 0;
    int j    = 0;
    int jCnt = 0;
    for (int i = 0; i < s_len; i++) {
        if (s[i] == '#') {
            jCnt++;
        }
    }
    cnt      = s_len - 2 * jCnt;
    res[cnt] = '\0';
    cnt--;

    for (int i = s_len - 1; i >= 2;) {
        if (s[i] == '#') {
            res[cnt] = (s[i - 2] - '1' + 1) * 10 + s[i - 1] - '0' - 10 + 'j';
            cnt--;
            i -= 3;
        } else {
            res[cnt--] = s[i] - '1' + 'a';
            i--;
        }
    }
    //还是整出了特例
    if (cnt > 0) {
        res[cnt--] = s[1] - '1' + 'a';
        res[cnt--] = s[0] - '1' + 'a';
    } else if (cnt == 0) {
        res[cnt] = s[0] - '1' + 'a';
    }
    return res;
}
