/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-20 12:10:58
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//理解题意出错，以下的解法并未通过
char* removeDuplicateLetters(char* s) {
    int  alphaDic[26] = {0};
    int  s_len        = strlen(s);
    int  cnt          = 0;
    bool zeroFlag     = false;
    for (int i = 0; i < s_len; i++) {
        alphaDic[s[i] - 'a']++;
        if (alphaDic[s[i] - 'a'] == 1) {
            cnt++;
        }
    }
    char* res    = (char*)malloc((cnt + 1) * sizeof(char));
    char* resPtr = res;
    for (int i = 0; i < 26; i++) {
        if (alphaDic[i] != 0) {
            *resPtr = i + 'a';
            *resPtr++;
        }
    }
    res[cnt] = '\0';
    return res;
}
//题解
//题解和我的处理大框架竟然是类似的！
char* removeDuplicateLetters(char* s) {
    int vis[26], num[26];
    memset(vis, 0, sizeof(vis));    //用于标记字符在栈中是否出现
    memset(num, 0, sizeof(num));    //存放字母出现的次数

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        num[s[i] - 'a']++;    // 26个字母各自出现的次数
    }

    char* stk    = malloc(sizeof(char) * 27);    //用于存放最后的结果
    int   stkTop = 0;                            //指示栈顶
    for (int i = 0; i < n; i++) {
        if (!vis[s[i] - 'a']) {
            while (stkTop > 0 && stk[stkTop - 1] > s[i]) {    //栈顶>0,且当前元素小于栈顶元素
                if (num[stk[stkTop - 1] - 'a'] > 0) {         //栈顶元素在后续还会看到
                    vis[stk[--stkTop] - 'a'] = 0;             //栈顶元素剔除，并将标志位清零
                } else {
                    break;
                }
            }
            vis[s[i] - 'a'] = 1;       //出现记为1
            stk[stkTop++]   = s[i];    //将当前遍历的元素添加至栈顶
        }
        num[s[i] - 'a'] -= 1;    //遍历后，出现的次数自减
    }
    stk[stkTop] = '\0';
    return stk;
}
