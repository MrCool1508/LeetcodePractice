/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-21 12:05:00
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//法一：双指针
bool isLongPressedName(char* name, char* typed) {
    bool res      = false;
    int  nameLen  = strlen(name);
    int  typedLen = strlen(typed);
    if (name[0] != typed[0]) {
        return false;
    }    //首字母不同，直接可判定不是
    // int typeCnt = 0;
    // int nameCnt = 0;
    for (int i = 1; i < typedLen + 1; i++) {
        // printf("%c | %c\r\n",*name,*typed);
        if ((*(name + 1)) != *(typed + 1)) {
            if (*name != *(typed + 1)) {
                return false;
            } else {
                *typed++;
                // typeCnt++;
            }
        } else {
            *name++;
            *typed++;
            // nameCnt++;
            // typeCnt++;
        }
        printf("--%d | %d--\r\n", nameCnt, typeCnt);
    }
    res = true;
    return res;
}
