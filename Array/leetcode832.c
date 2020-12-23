/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-23 17:24:43
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//先水平镜像翻转，再将每个数字取反
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize        = ASize;
    *returnColumnSizes = AColSize;

    int temp = 0;
    for (int i = 0; i < ASize; i++) {
        temp = 0;
        for (int j = 0; j < (ASize + 1) / 2; j++) {
            temp                = A[i][j];    //先翻转，同时取反
            A[i][j]             = !A[i][ASize - 1 - j];
            A[i][ASize - 1 - j] = !temp;
        }
    }
    return A;
}
