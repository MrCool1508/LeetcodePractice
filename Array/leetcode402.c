/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-15 12:11:27
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//如果数字串中含有0，则把0之前
// int myCpr(const void* a, const void* b) {
//     return *(int*)a - *(int*)b;
// }
//暴力解法：找出所有全排列，再qsort最小
//以下思路行不通....
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
char* removeKdigits(char* num, int k) {
    int numLen = strlen(num);
    if (k == numLen) {
        return NULL;
    }
    //整理成数组
    int  zeroFlag = 0;
    int* temp     = calloc(numLen, sizeof(int));
    for (int i = 0; i < numLen; i++) {
        temp[i] = num[i] - '0';
        if (temp[i] == 0) {
            zeroFlag = 1;
        }
    }
    // qsort该数组
    int* tempQsort = calloc(numLen, sizeof(int));
    memcpy(tempQsort, temp, numLen * sizeof(int));
    qsort(tempQsort, numLen, sizeof(int), myCpr);
    if (0 == zeroFlag) {
        int   resLen = numLen - k + 1;
        char* res    = (char*)malloc(resLen * sizeof(char));
        char* ptr    = res;
        for (int i = 0; i < numLen; i++) {
            for (int j = 0; j < numLen - k; j++) {
                if (num[i] == tempQsort[j] + '0') {
                    *ptr         = tempQsort[j] + '0';
                    tempQsort[j] = -100;
                    *ptr++;
                    break;
                }
            }
        }
        res[resLen - 1] = '\0';
        return res;
    } else {
        return NULL;    //没想好怎么写
    }
}
