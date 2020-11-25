/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-03 11:30:07
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * 方法一：
 *
 *
 * */
// int* myCpr(const void* a, const void* b) {
//     return *(int*)a - *(int*)b;
// }
// int repeatedNTimes(int* A, int ASize) {
//     int res = 0;
//     qsort(A, ASize, sizeof(int), myCpr);
//     int* ptr = A;
//     for (int i = 0; i < ASize - 1; i++, *ptr++) {
//         if (*ptr == *(ptr + 1)) {
//             res = *ptr;
//             break;
//         }
//     }
//     return res;
// }
/**
 * 方法二
 *
 *
 * */
// int repeatedNTimes(int* A, int ASize) {
//     int res = 0;
//     int* ptr = A;
//     for (int i = 0; i < ASize - 3; i++, *ptr++) {
//         if ((*ptr == *(ptr + 1)) || (*ptr == *(ptr + 2)) || (*ptr == *(ptr + 3))) {
//             res = *ptr;
//             break;
//         }
//     }

//     if ((*ptr == *(ptr + 1)) || (*ptr == *(ptr + 2))) {
//         res = *ptr;
//     } else if (*(ptr + 1) == *(ptr + 2)) {
//         res = *(ptr + 1);
//     }
//     return res;
// }
/**
 * 方法三
 *
 *
 * */
int repeatedNTimes(int* A, int ASize) {
    int  res = 0;
    int* ptr = A;
    for (int i = 0; i < ASize - 3; i++, *ptr++) {
        if (!(*ptr ^ *(ptr + 1)) || !(*ptr ^ *(ptr + 2)) || !(*ptr ^ *(ptr + 3))) {
            res = *ptr;
            break;
        }
    }

    if (!(*ptr ^ *(ptr + 1)) || !(*ptr ^ *(ptr + 2))) {
        res = *ptr;
    } else if (!(*(ptr + 1) ^ *(ptr + 2))) {
        res = *(ptr + 1);
    }
    return res;
}
