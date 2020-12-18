/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-18 13:26:15
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//第一反应，排序后二分查找
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void str2Char(char* s, int s_len, int* s_char) {
    for (int i = 0; i < s_len; i++) {
        s_char[i] = s[i] - 'a';
    }
}
char findTheDifference(char* s, char* t) {
    int s_len = strlen(s);
    if (!s_len) {
        return t[0];
    }
    int  t_len  = strlen(t);
    int* s_char = malloc(s_len * sizeof(int));
    int* t_char = malloc(t_len * sizeof(int));
    str2Char(s, s_len, s_char);
    str2Char(t, t_len, t_char);

    qsort(s_char, s_len, sizeof(int), myCpr);
    qsort(t_char, t_len, sizeof(int), myCpr);
    char res;
    for (int i = 0; i < s_len; i++) {
        if (s_char[i] != t_char[i]) {
            res = t_char[i] + 'a';
            free(s_char);
            free(t_char);
            return res;
        }
    }
    res = t_char[t_len - 1] + 'a';
    free(s_char);
    free(t_char);
    return res;
}
//哈希应该可以，但是我不会！
//不排序，直接用桶试试,此法贼快！
char findTheDifference(char* s, char* t) {
    int s_len = strlen(s);
    if (!s_len) {
        return t[0];
    }
    int t_len        = strlen(t);
    int alphaDic[26] = {0};
    for (int i = 0; i < s_len; i++) {
        alphaDic[s[i] - 'a']++;
        alphaDic[t[i] - 'a']--;
    }
    alphaDic[t[t_len - 1] - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (alphaDic[i] != 0) {
            return i + 'a';
        }
    }
    return ' ';
}
//还可以用异或算法，这贼机智！
//还可以拼接字符串，字母次数出现奇数次的为答案！
//还可以对ascii码求和，最终结果差即为待求字母！
char findTheDifference(char* s, char* t) {
    int s_len = strlen(s);
    if (!s_len) {
        return t[0];
    }
    // int t_len = strlen(t);
    int res = 0;
    for (int i = 0; i < s_len; i++) {
        res += s[i] - 'a';
        res -= t[i] - 'a';
    }
    res -= t[s_len] - 'a';
    return -res + 'a';
}
