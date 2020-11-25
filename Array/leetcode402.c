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
char* nonZeroProcess(char* num, int k) {
    int  numLen = strlen(num);
    int* temp   = (int*)calloc(numLen, sizeof(int));
    for (int i = 0; i < strlen; i++) {
        temp[i] = num[i] - '0';
    }
    int permutationLen = numLendec int* permutation = (int*)calloc( )
}
char* removeKdigits(char* num, int k) {
    int num_Len  = strlen(num);    //数字串的位数
    int zero_pos = -1;
    for (int i = 0; i < num_Len; i++) {
        if (num[i] == '0') {
            zero_pos = i;
            break;
        }
    }
    if (zero_pos == -1) {
        /* code */
    } else {
        /* code */
    }

    //滑动窗口
}
