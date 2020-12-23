/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-23 17:15:49
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//提交之后通过了，对比看一年前写的代码，竟然觉得自己成长了许多！
int firstUniqChar(char* s) {
    int alphaDic[26] = {0};
    int s_len        = strlen(s);
    for (int i = 0; i < s_len; i++) {
        alphaDic[s[i] - 'a']++;
    }
    int res = -1;
    for (int i = 0; i < s_len; i++) {
        if (1 == alphaDic[s[i] - 'a']) {
            res = i;
            return res;
        }
    }
    return res;
}
