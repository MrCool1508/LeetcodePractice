// /*
//  * @file: 文件名
//  * @author: hzy
//  * @version: V1.0.0
//  * @date: 2020-10-27 13:17:31
//  * @brief: 模块目的、功能
//  * @History:
//  * <author><date><version><brief>
//  */
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// char* removeDuplicates(char* S) {
//     int   s_len    = strlen(S);
//     int   cnt      = 0;
//     int   temp     = 0;
//     int   leftTemp = 0;
//     int*  pos      = (int*)calloc(s_len, sizeof(int));
//     char *forwardPtr, *backPtr, *s_temp;
//     forwardPtr = S;
//     backPtr    = S;
//     s_temp     = S;
//     for (int i = 0; i < s_len - 1; i++) {
//         if (*(S + i) == *(S + i + 1)) {
//             cnt += 2;
//             *(pos + i)     = 1;
//             *(pos + i + 1) = 1;
//             // forwardPtr     = S + i;
//             backPtr = S + i + 1;
//             printf("!!!S[%d]:%c,S[%d]:%c\r\n", i, *(S + i), i + 1, *(S + i + 1));
//             if ((backPtr - s_temp + 1) == cnt) {
//                 i += 1;
//             } else {
//                 //意味着有pos = 0
//                 if (backPtr < S + s_len - 1) {
//                     *backPtr++;
//                     temp++;
//                 }
//                 while ((forwardPtr > S) {
//                     if (*(pos + i)) {
//                         /* code */
//                     }

//                     /* code */
//                 }
//                     *forwardPtr--;
//                     leftTemp++;
//             }
//         }

//         // while ((forwardPtr > S) && (backPtr < S + s_len - 1)) {
//         //     //  printf("cnt:%d\r\n",cnt);
//         //     *forwardPtr--;
//         //     *backPtr++;
//         //     temp++;
//         //     leftTemp++;
//         //     while (*(pos + i - leftTemp) == 1) {
//         //         *forwardPtr--;
//         //         leftTemp++;
//         //         if (leftTemp == i) {
//         //             break;
//         //         }
//         //     }
//         //     // printf("???\r\n");
//         //     if (*forwardPtr == *backPtr) {
//         //         *(pos + i - temp)     = 1;
//         //         *(pos + i + 1 + temp) = 1;
//         //         cnt += 2;
//         //         continue;
//         //     } else {
//         //         // printf("---tp:%d, i:%d\r\n",temp, i);
//         //         break;
//         //     }
//         // }
//         // i += 1 + temp;    //从backPtr后一位重新开始对比
//         // temp = 0;

//         printf("cnt:%d\r\n", cnt);
//     }
// }

// if (cnt == 0) {
//     return S;
// } else if (cnt == s_len) {
//     char* res = (char*)malloc(sizeof(char));
//     res[0]    = '\0';
//     return res;
// } else {
//     char* res = (char*)malloc(sizeof(char) * (s_len - cnt + 1));
//     char* p   = res;
//     for (int i = 0; i < s_len; i++) {
//         if (pos[i] == 0) {
//             *res = S[i];
//             *res++;
//         }
//     }
//     *res = '\0';
//     return p;
// }
// }

char* removeDuplicates(char* S) {
    int   cnt      = 0;
    int   temp     = 0;
    int   leftTemp = 0;
    int   s_len    = strlen(S);
    int*  pos      = (int*)calloc(s_len, sizeof(int));
    char *forwardPtr, *backPtr, *s_temp;

    forwardPtr = S;
    backPtr    = S;
    s_temp     = S;

    for (int i = 0; i < s_len - 1; i++) {
        if (*(S + i) == *(S + i + 1)) {
            cnt += 2;
            *(pos + i)     = 1;
            *(pos + i + 1) = 1;
            // forwardPtr     = S + i;
            if ((i + 2) <= (s_len - 1)) {
                backPtr = S + i + 2;    //指针指向当前数对的后一位
            } else {
                //
            }

            forwardPtr = S + i;
            while (forwardPtr > S) {
                *(pos + i)
            }

            printf("!!!S[%d]:%c,S[%d]:%c\r\n", i, *(S + i), i + 1, *(S + i + 1));
            if ((backPtr - s_temp + 1) == cnt) {
                i += 1;
            } else {
                //意味着有pos = 0
                if (backPtr < S + s_len - 1) {
                    *backPtr++;
                    temp++;
                }
                while ((forwardPtr > S) {
                    if (*(pos + i)) {
                        /* code */
                    }

                    /* code */
                }
                    *forwardPtr--;
                    leftTemp++;
            }
        }
        printf("cnt:%d\r\n", cnt);
    }
}

if (cnt == 0) {
    return S;
} else if (cnt == s_len) {
    char* res = (char*)malloc(sizeof(char));
    res[0]    = '\0';
    return res;
} else {
    char* res = (char*)malloc(sizeof(char) * (s_len - cnt + 1));
    char* p   = res;
    for (int i = 0; i < s_len; i++) {
        if (pos[i] == 0) {
            *res = S[i];
            *res++;
        }
    }
    *res = '\0';
    return p;
}
}
