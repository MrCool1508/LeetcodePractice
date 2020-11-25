/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int char2Num(char a) {
    int res = 0;
    res     = a - 'a';
    return res;
}
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    int* res       = (int*)calloc(2, sizeof(int));
    int  temp      = 0;
    int  fullRow   = 0;
    int  remainNum = 0;
    int  s_len     = strlen(S);

    for (int i = 0; i < s_len; i++) {
        temp = widths[char2Num(*S)];
        remainNum += temp;
        if (remainNum > 100) {
            fullRow++;
            remainNum = temp;
        }
        *S++;
    }
    if (remainNum <= 100) {
        fullRow++;
    }

    res[0]      = fullRow;
    res[1]      = remainNum;
    *returnSize = 2;
    return res;
}
