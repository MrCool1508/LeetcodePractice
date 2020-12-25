/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-25 15:49:26
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//平安夜分糖果，圣诞节分饼干，明天分手=。 =
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), myCpr);
    qsort(s, sSize, sizeof(int), myCpr);
    int res = 0;
    int j   = gSize - 1;

    for (int i = sSize - 1; i >= 0;) {
        if (j >= 0) {
            // printf("s[%d]:%d, g[%d]:%d\r\n",i,s[i],j,g[j]);
            if (s[i] >= g[j]) {
                res++;
                i--;
                // printf("===%d, %d===\r\n",i, j);
            }
            j--;
        } else {
            break;
        }
    }
    return res;
}
//对比一下题解
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), myCpr);
    qsort(s, sSize, sizeof(int), myCpr);
    int numOfChildren = gSize, numOfCookies = sSize;
    int count = 0;
    for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
        while (j < numOfCookies && g[i] > s[j]) {
            j++;
        }
        if (j < numOfCookies) {
            count++;
        }
    }
    return count;
}
