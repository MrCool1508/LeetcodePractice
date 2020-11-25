/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-19 11:30:07
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
bool backspaceCompare(char* S, char* T) {
    bool  res      = false;
    int   s_len    = strlen(S);
    int   t_len    = strlen(T);
    char* s_res    = (char*)malloc(sizeof(char) * (s_len + 1));
    char* t_res    = (char*)malloc(sizeof(char) * (t_len + 1));
    char  lastChar = '#';
    printf("%d|%d\r\n", s_len, t_len);
    for (int i = 0; i < s_len + 1; i++) {
        if (*(S + i) != '#') {
            *s_res   = *(S + i);
            lastChar = *s_res;
            *s_res++;
        }
    }

    return res;
}
