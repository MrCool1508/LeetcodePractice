/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2021-03-31 22:52:03
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char* restoreString(char* s, int* indices, int indicesSize) {
    int   s_len = strlen(s);
    char* res   = (char*)malloc((s_len + 1) * sizeof(char));
    printf("%d--size\r\n", sizeof(*res));
    int*  indiTemp = NULL;
    char* sTemp    = NULL;
    char* resTemp  = res;
    for (int i = 0; i < s_len;) {
        indiTemp = indices;
        sTemp    = s;
        printf("--%d\r\n", i);
        while (*indiTemp != i) {
            *indiTemp++;
            *sTemp++;
        }
        i++;

        *resTemp = *sTemp;
        *resTemp++;
    }
    indicesSize = s_len;
    *resTemp    = '\0';
    return res;
}

int main(int argc, char const* argv[]) {
    int   test        = 0;
    char* sExample    = "codeleet";
    int   inExample[] = {4, 5, 6, 7, 0, 2, 1, 3};
    printf("%s | %d\r\n", restoreString(sExample, inExample, test), test);
    return 0;
}
