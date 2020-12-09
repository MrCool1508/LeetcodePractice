/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-09 21:00:17
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//第一反应双指针
//第二反应strtok
char* replaceSpaces(char* S, int length) {
    int   S_Len   = strlen(S);
    char* res     = (char*)malloc((3 * length + 1) * sizeof(char));
    char* resPtr  = res;
    int   cnt     = 0;
    int   loopCnt = length;
    for (int i = 0; i < length; i++) {
        if (S[i] != ' ') {
            *resPtr = S[i];
            cnt++;
        } else {
            if (cnt == length) break;
            *resPtr = '%';
            *resPtr++;
            *resPtr = '2';
            *resPtr++;
            *resPtr = '0';
            cnt += 3;
            length += 2;
        }
        *resPtr++;
    }
    *resPtr = '\0';
    memcpy(S, res, S_Len);
    free(res);
    return S;
}
//抄题解
char* replaceSpaces(char* S, int length) {
    int   i        = 0;
    int   j        = 0;
    int   retlen   = 0;
    int   spacenum = 0;
    char* ret      = NULL;

    for (i = 0; i < length; i++) {
        if (S[i] == ' ') {
            spacenum++;
        }
    }

    retlen = length + 2 * spacenum;
    ret    = malloc(retlen + 1);

    for (i = length - 1, j = retlen - 1; i >= 0, j >= 0; i--) {
        if (S[i] == ' ') {
            ret[j--] = '0';
            ret[j--] = '2';
            ret[j--] = '%';
        } else {
            ret[j--] = S[i];
        }
    }

    ret[retlen] = '\0';

    return ret;
}
//下述两种题解速度最快
char* replaceSpaces(char* S, int length) {
    char* ans = (char*)malloc(sizeof(char) * (3 * length + 1));
    int   i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (S[i] == ' ') {
            ans[j++] = '%';
            ans[j++] = '2';
            ans[j++] = '0';
        } else
            ans[j++] = S[i];
    }
    ans[j] = '\0';
    return ans;
}
char* replaceSpaces(char* S, int length) {
    int i, spaceNums = 0;
    // 1.数空格
    for (i = 0; i < length; i++) {
        if (S[i] == ' ') spaceNums++;
    }
    // 2.处理末尾:由于空格占一个长度，即抵消%，20就是多的两个长度
    int last_idx    = length + spaceNums * 2 - 1;
    S[last_idx + 1] = '\0';    // 长度截断
    // 3.元素右移，遇到空格填%20:因此必须从最后开始避免覆盖
    for (i = length - 1; i >= 0; i--) {
        if (S[i] == ' ') {    // 注意反向！
            S[last_idx--] = '0';
            S[last_idx--] = '2';
            S[last_idx--] = '%';
        } else
            S[last_idx--] = S[i];
    }
    return S;
}
