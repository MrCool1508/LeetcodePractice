/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 15:27:13
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int titleToNumber(char* s) {
    int res   = 0;
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++, *s++) {
        // printf("i:%7d,",i);
        res += (*s - 'A' + 1) * pow(26, s_len - i - 1);
        // printf("res:%7d\r\n",res);
    }
    return res;
}
