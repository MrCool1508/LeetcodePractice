/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-08 19:37:09
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//求表面积，可以分解为六个面
//可以看成六个面上的投影面积和
//投影面积从某个意义上来说，找最大值
//表面积S=2*（非零的数字个数+每行最大的数字和+每列最大的数字和）
//此解法忽略了空心的情况。
int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int  res_area      = 0;
    int  upDownArea    = 0;
    int  frontBackArea = 0;
    int  leftRightArea = 0;
    int* rowMax        = (int*)calloc(gridSize, sizeof(int));
    int* colMax        = (int*)calloc(*gridColSize, sizeof(int));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] != 0) {
                upDownArea++;
            }
            if (grid[i][j] > rowMax[i]) {
                rowMax[i] = grid[i][j];
            }
            if (grid[i][j] > colMax[j]) {
                colMax[j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < gridSize; i++) {
        frontBackArea += rowMax[i];
    }
    for (int i = 0; i < *gridColSize; i++) {
        leftRightArea += colMax[i];
    }

    res_area = 2 * (upDownArea + frontBackArea + leftRightArea);
    free(rowMax);
    free(colMax);
    return res_area;
}
