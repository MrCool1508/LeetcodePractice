/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-08 16:30:07
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
// char* gcdOfStrings(char* str1, char* str2) {
//     if (0 == strcmp(str1, str2)) {
//         return str1;
//     }
// }
//抄作业
/**
 * char *strstr(const char *haystack, const char *needle)
 * 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。
 * int strcmp(const char *str1, const char *str2)
 * 把 str1 所指向的字符串和 str2 所指向的字符串进行比较。
 * 论strstr和strcmp的妙用，写这段code的人贼聪明啊！感慨！
 */
char* gcdOfStrings(char* str1, char* str2) {
    // if (strstr(str1, str2) == NULL && strstr(str2, str1) == NULL) 原答案
    if (!(strstr(str1, str2) == str1 || strstr(str2, str1) == str2)) return "";
    int p_a = 0, p_b = 0, cmp = 0;
    do {
        cmp = strcmp(str1 + p_a, str2 + p_b);
        cmp > 0 ? (p_a += strlen(str2 + p_b)) : (p_b += strlen(str1 + p_a));
        // if (strstr(str1 + p_a, str2 + p_b) == NULL && strstr(str2 + p_b, str1 + p_a) == NULL)
        if (!(strstr(str1 + p_a, str2 + p_b) == (str1 + p_a) || strstr(str2 + p_b, str1 + p_a) == (str2 + p_b))) return "";
    } while (cmp);
    return str1 + p_a;
}

// #include <stdio.h>
// #include <string.h>

// int main( ) {
//     char str1[15];
//     char str2[15];
//     int  ret;

//     strcpy(str1, "ABCDEFf");
//     strcpy(str2, "ABCDEFfe");

//     ret = strcmp(str1, str2);
//     printf("%s\r\n", str1 + 3);
//     if (ret < 0) {
//         printf("str1 小于 str2");
//     } else if (ret > 0) {
//         printf("str1 大于 str2");
//     } else {
//         printf("str1 等于 str2");
//     }

//     return (0);
// }
