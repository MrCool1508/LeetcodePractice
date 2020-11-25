/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-09 11:00:57
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes) {
    if (K == 0) {
        *returnSize = 0;
        int** res;
        return res;
    } else if (K >= pointsSize) {
        *returnSize        = pointsSize;
        *returnColumnSizes = malloc(sizeof(int) * pointsSize);
        int** res          = (int**)malloc(pointsSize * sizeof(int*));

        for (int i = 0; i < pointsSize; i++) {
            res[i]                  = (int*)malloc(2 * sizeof(int));
            (*returnColumnSizes)[i] = 2;
            memcpy(res[i], points[i], 2 * sizeof(int));
        }
        return res;
    }
    int* disSqure = (int*)calloc(pointsSize, sizeof(int));
    for (int i = 0; i < pointsSize; i++) {
        disSqure[i] = (points[i][0]) * (points[i][0]) + (points[i][1]) * (points[i][1]);
    }
    int* disSqureTemp = (int*)calloc(pointsSize, sizeof(int));

    memcpy(disSqureTemp, disSqure, pointsSize * sizeof(int));
    qsort(disSqureTemp, pointsSize, sizeof(int), myCpr);

    *returnSize        = K;
    *returnColumnSizes = malloc(K * sizeof(int));

    int** res = (int**)malloc(K * sizeof(int*));

    for (int i = 0; i < K; i++) {
        res[i]                  = malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
        for (int j = 0; j < pointsSize; j++) {
            if (disSqureTemp[i] == disSqure[j]) {
                disSqure[j] = -1;    //避免重复
                memcpy(res[i], points[j], 2 * sizeof(int));
                // printf("res[%d]:[%d,%d]\r\n",i,res[i][0],res[i][1]);
                break;
            }
        }
    }
    free(disSqure);
    free(disSqureTemp);
    return res;
}
/**
 * 还是没吃透qsort
 *
 *
 * */
int cmp(const void* _a, const void* _b) {
    int *a = *(int**)_a, *b = *(int**)_b;
    return a[0] * a[0] + a[1] * a[1] - b[0] * b[0] - b[1] * b[1];
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes) {
    qsort(points, pointsSize, sizeof(int*), cmp);
    *returnSize        = K;
    *returnColumnSizes = malloc(sizeof(int) * K);
    int** ret          = malloc(sizeof(int*) * K);
    for (int i = 0; i < K; i++) {
        (*returnColumnSizes)[i] = 2;
        ret[i]                  = malloc(sizeof(int) * 2);
        ret[i][0] = points[i][0], ret[i][1] = points[i][1];
    }
    return ret;
}
