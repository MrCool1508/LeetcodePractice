/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-06 00:16:18
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int bitCntCal(int a) {
    int res = 0;
    while (a) {
        if (a % 2 == 1) {
            res++;
        }
        a /= 2;
    }
    return res;
}
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), myCpr);
    int* bitCnt = (int*)calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            bitCnt[i] = 0;
        } else {
            bitCnt[i] = bitCntCal(arr[i]);
        }
    }
    int* bitCntTemp = (int*)calloc(arrSize, sizeof(int));
    memcpy(bitCntTemp, bitCnt, arrSize * sizeof(int));
    qsort(bitCntTemp, arrSize, sizeof(int), myCpr);

    int* res = (int*)calloc(arrSize, sizeof(int));
    int* p   = res;
    // for(int i=0;i<arrSize;i++){
    //     printf("b:%d | bt:%d\r\n",bitCnt[i],bitCntTemp[i]);
    // }
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (bitCntTemp[i] == bitCnt[j]) {
                *p        = arr[j];
                bitCnt[j] = -1;
                *p++;
            }
        }
    }
    // for(int i=0;i<arrSize;i++){
    //     printf("res:%d\r\n",res[i]);
    // }
    free(bitCnt);
    free(bitCntTemp);
    *returnSize = arrSize;
    return res;
}
