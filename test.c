/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-03 17:40:31
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>

int disCal(x, y) {
    return sqrt(x * x + y * y);
}
int main(int argc, char const *argv[]) {
    printf("dis:%d\r\n", disCal(5, 25));
    return 0;
}
