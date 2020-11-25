/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-08 13:31:40
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
char** slideString(char* S, int* returnSize, int* slideLen, int slideLenSize) {
    // string切片为单词，并且将重复的单词合并，返回结果按照单词长度由小到大排列。
    int   s_len = strlen(S);
    char* temp  = S;

    if (!s_len) {
        *returnSize = 0;
    } else {
        int wordCnt = 0;
        while (*temp != '\0') {
            if (*temp == ' ') {
                wordCnt++;
            }
        }
        slideLenSize         = wordCnt + 1;
        int* slideLenTemp    = (int*)calloc(slideLenSize, sizeof(int));
        int* slideLenTempPtr = slideLenTemp wordCnt = 0;
        while (*temp != '\0') {
            if (*temp == ' ') {
                *slideLenTempPtr = wordCnt;
                wordCnt          = 0;
                *slideLenTempPtr++;
            }
            wordCnt++;
        }
    }
    return res;
}
char** uncommonFromSentences(char* A, char* B, int* returnSize) {
    int  a_len     = strlen(A);
    int  b_len     = strlen(B);
    int* a_ptr     = A;
    int* b_ptr     = B;
    int  wordCnt_A = 0;
    int  wordCnt_B = 0;
    int  maxLen    = (a_len > b_len) ? a_len : b_len;

    for (int i = 0; i < maxLen; i++) {
    }
}
