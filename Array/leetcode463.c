/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-30 19:23:03
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

//如果是1，则该格子向上下左右格子比较，相同为0，相异为1，再求和
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int   res          = 0;
    int   gridSizeTemp = gridSize + 2;
    int** gridTemp     = (int**)calloc(gridSizeTemp, sizeof(int*));
    int*  gridColSizeTemp;
    int   gridCS = gridColSize[0] + 2;

    for (int i = 0; i < gridSizeTemp; i++) {
        gridColSizeTemp = (int*)calloc((*gridColSize) + 2, sizeof(int));
        gridTemp[i]     = gridColSizeTemp;
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            gridTemp[i + 1][j + 1] = grid[i][j];
        }
    }

    for (int i = 1; i < gridSizeTemp - 1; i++) {
        for (int j = 1; j < gridCS - 1; j++) {
            // printf("gT[%d][%d]:%d\r\n",i,j,gridTemp[i][j]);
            if (gridTemp[i][j] == 1) {
                if (gridTemp[i][j] ^ gridTemp[i - 1][j]) {
                    res++;
                }
                if (gridTemp[i][j] ^ gridTemp[i][j - 1]) {
                    res++;
                }
                if (gridTemp[i][j] ^ gridTemp[i][j + 1]) {
                    res++;
                }
                if (gridTemp[i][j] ^ gridTemp[i + 1][j]) {
                    res++;
                }
                // printf("0:%d|s:%d|x:%d|l:%d|r:%d \r\n",gridTemp[i][j],gridTemp[i - 1][j], gridTemp[i + 1][j],gridTemp[i][j - 1],gridTemp[i][j +
                // 1]);
            }
        }
    }
    free(gridTemp);
    return res;
}
