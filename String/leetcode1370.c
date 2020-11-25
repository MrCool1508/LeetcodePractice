/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-25 17:05:35
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

char* sortString(char* s) {
    int s_len = strlen(s);
    if (s_len == 0) {
        return NULL;
    }
    char* res  = (char*)malloc((s_len + 1) * sizeof(char));
    res[s_len] = '\0';
    char* p    = res;
    /*土方法*/
    char* alpha     = (char*)malloc(26 * sizeof(char));
    int*  alphaFreq = (int*)calloc(26, sizeof(int));
    //创建26个字母
    for (int i = 0; i < 26; i++) {
        alpha[i] = 'a' + i;
    }
    //记录字符串中出现各字母的次数
    for (int j = 0; j < s_len; j++) {
        for (int i = 0; i < 26; i++) {
            if (s[j] == alpha[i]) {
                alphaFreq[i]++;
                break;
            }
        }
    }
    int resCnt = 0;
    //安排升序和降序
    while (resCnt < s_len) {
        for (int i = 0; i < 26; i++) {
            if (alphaFreq[i] > 0) {
                *p = alpha[i];
                alphaFreq[i]--;
                resCnt++;
                *p++;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (alphaFreq[i] > 0) {
                *p = alpha[i];
                alphaFreq[i]--;
                resCnt++;
                *p++;
            }
        }
    }
    return res;
}
