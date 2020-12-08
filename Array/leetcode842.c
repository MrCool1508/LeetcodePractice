/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-08 15:20:58
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int* splitIntoFibonacci(char* S, int* returnSize) {
    int  S_Len = strlen(S);
    int* res   = NULL;
    if (S_Len == 0) {
        return NULL;
    } else if (0 == S[0]) {
        if (1 == S_Len) {
            *returnSize = 1;
            res         = calloc(1, sizeof(int));
            return res;
        } else {
            return NULL;
        }
    }
}
