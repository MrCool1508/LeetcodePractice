/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-22 21:50:03
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//测试单例中有一条“   ”，下述解法无法通过
char* replaceSpace(char* s) {
    int s_len = strlen(s);
    if (0 == s_len) {
        return s;
    }
    int cnt = 0;
    for (int i = 0; i < s_len; i++) {
        if (s[i] == ' ') {
            cnt++;
        }
    }
    int   resLen    = s_len + 2 * cnt + 1;
    char* res       = (char*)malloc(resLen * sizeof(char));
    res[resLen - 1] = '\0';
    char* s_pair    = " ";
    char* token;
    token      = strtok(s, s_pair);
    int tokLen = strlen(token);
    memcpy(res, token, tokLen);
    int resPos      = tokLen;
    res[resPos]     = '%';
    res[resPos + 1] = '2';
    res[resPos + 2] = '0';
    resPos += 3;
    while (token) {
        token  = strtok(NULL, s_pair);
        tokLen = strlen(token);
        memcpy(res + resPos, token, tokLen);
        resPos += tokLen;
        if (resPos == resLen - 1) {
            break;
        }
        res[resPos]     = '%';
        res[resPos + 1] = '2';
        res[resPos + 2] = '0';
        resPos += 3;
    }
    return res;
}
//重写了
char* replaceSpace(char* s) {
    int s_len = strlen(s);
    if (0 == s_len) {
        return s;
    }
    char* res    = (char*)malloc((s_len * 3 + 1) * sizeof(char));
    char* resPtr = res;
    int   cnt    = 0;
    for (int i = 0; i < s_len; i++) {
        if (s[i] == ' ') {
            *resPtr = '%';
            *resPtr++;
            *resPtr = '2';
            *resPtr++;
            *resPtr = '0';
        } else {
            *resPtr = s[i];
        }
        *resPtr++;
    }
    *resPtr = '\0';
    return res;
}
