/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 22:51:05
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int* myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int distributeCandies(int* candies, int candiesSize) {
    int  res     = 0;
    int  sameCnt = 1;
    int* p_fast  = candies + 1;
    // printf("%d\r\n",*p_fast);
    qsort(candies, candiesSize, sizeof(int), myCpr);
    // int* numCnt = (int*)calloc(candiesSize / 2, sizeof(int));
    // int* p_slow = numCnt;

    for (int i = 1; i < candiesSize; i++) {
        // if (*p_fast == *(p_fast - 1)) {
        //     // p_slow++;
        // } else {
        //     // *p_slow++;
        //     // p_slow++;
        //     sameCnt++;
        // }
        if (*p_fast != *(p_fast - 1)) {
            sameCnt++;
        }
        *p_fast++;
    }
    // printf("same:%d, size:%d\r\n",sameCnt,candiesSize);
    res = (sameCnt > candiesSize / 2) ? (candiesSize / 2) : sameCnt;
    return res;
}
