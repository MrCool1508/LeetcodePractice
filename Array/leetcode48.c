/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-19 16:18:35
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp = 0;
    int row  = matrixSize;
    int n    = row;
    //先行列方向互换（关于对角线对称）
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            temp         = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    //每行关于中间元素对称互换
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            // printf("matrix[%d][%d]:%d\r\n",i,j,matrix[i][j]);
            temp                 = matrix[i][j];
            matrix[i][j]         = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}
