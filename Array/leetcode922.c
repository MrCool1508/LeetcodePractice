/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 15:11:42
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int* res    = (int*)calloc(ASize, sizeof(int));
    int* p_even = res;
    int* p_odd  = res + 1;
    for (int i = 0; i < ASize; i++, *A++) {
        if (*A % 2) {
            *p_odd = A;
            *p_odd += 2;
        } else {
            *p_even = A;
            *p_even += 2;
        }
    }

    *returnSize = ASize;
    return res;
}

int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int* res = (int*)calloc(ASize, sizeof(int));
    // memcpy(res, A, ASize * sizeof(int));
    qsort(A, ASize, sizeof(int), myCpr);
    int  cnt   = 0;
    int* p     = A;
    int* p_res = res;
    for (int i = 0; i < ASize; i++) {
        if (*p % 2 == 0) {
            *p_res = p;
            *p++;
            p_res += 2;
        } else {
            /* code */
        }
    }

    *returnSize = ASize;
    return res;
}
