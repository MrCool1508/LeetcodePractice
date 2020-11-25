/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-04 11:21:31
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * 假设有n个区间，区间左端点为A1，A2，....，Ai，...，An；
 * 区间右端点为B1，B2，....，Bi，...，Bn；
 * 且区间已经按照升序排列。
 * 新插入区间为[A,B]。
 *
 * 算法分析：
 * 1、准备工作：将左右端点各自新建一个数组，并且通过加入A和B进行排列：
 *    [A1,A2,A,A3][B1,B2,B3,B]，并建立一个位置序对[[0,0][1,1][3,2][2,3]]
 *    最后一个序对存放[A,B]的位置。
 * 2、将A与B2,B3做比较：
 *      2.1：A<=B2,return [[A1,B1][A2,]]
 *
 *
 *
 *
 **/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define FUNCTION_1

int* myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize,
             int** returnColumnSizes) {
    /*方法一*/
    int** res;
#ifdef FUNCTION_1
    int newLen = intervalsSize + 1;
    if (newInterval[1] < intervals[0][0]) {
        //将[A，B]作为第一组放回
        *returnSize             = newLen;
        res                     = (int**)malloc(newLen * sizeof(int*));
        returnColumnSizes       = (int**)malloc(newLen * sizeof(int*));
        res[0]                  = (int*)malloc(2 * sizeof(int));
        returnColumnSizes[0]    = (int*)malloc(sizeof(int));
        res[0][0]               = newInterval[0];
        res[0][1]               = newInterval[1];
        returnColumnSizes[0][0] = 2;
        for (int i = 1; i < newLen; i++) {
            res[i]               = (int*)malloc(2 * sizeof(int));
            returnColumnSizes[i] = (int*)malloc(sizeof(int));
            memcpy(res[i], intervals[i - 1], 2);
            returnColumnSizes[i][0] = 2;
        }
        return res;
    }
    if (newInterval[0] > intervals[intervalsSize - 1][1]) {
        //将[A，B]作为最后一组放回
        *returnSize       = newLen;
        res               = (int**)malloc(newLen * sizeof(int*));
        returnColumnSizes = (int**)malloc(newLen * sizeof(int*));
        for (int i = 0; i < intervalsSize; i++) {
            res[i]               = (int*)malloc(2 * sizeof(int));
            returnColumnSizes[i] = (int*)malloc(sizeof(int));
            memcpy(res[i], intervals[i], 2);
            returnColumnSizes[i][0] = 2;
        }
        res[intervalsSize]                  = (int*)malloc(2 * sizeof(int));
        returnColumnSizes[intervalsSize]    = (int*)malloc(sizeof(int));
        res[intervalsSize][0]               = newInterval[0];
        res[intervalsSize][1]               = newInterval[1];
        returnColumnSizes[intervalsSize][0] = 2;
        return res;
    }

    int* rowTemp = (int*)calloc(newLen, sizeof(int));
    int* colTemp = (int*)calloc(newLen, sizeof(int));
    for (int i = 0; i < intervals; i++) {
        rowTemp[i] = intervals[i][0];
        colTemp[i] = intervals[0][i];
    }
    rowTemp[intervalsSize] = newInterval[0];
    colTemp[intervalsSize] = newInterval[1];
    qsort(rowTemp, newLen, sizeof(int), myCpr);
    qsort(rowTemp, newLen, sizeof(int), myCpr);
    int leftPos  = 0;
    int rightPos = 0;
    //找到插入区间左端点A在原数列左端点Ai序列的位置
    for (int i = 0; i < newLen; i++) {
        if (rowTemp[i] == newInterval[0]) {
            leftPos = i;
            break;
        }
    }
    //在原数列中，A最大，将A端点的位置与原序列最后一个右端点进行比较
    if (leftPos == intervalsSize) {
        //比较右端点
        if (newInterval[1] >= intervals[intervalsSize - 1][1]) {
            //复制原数列，并将intervals[intervalsSize - 1][1]的值更为B
        } else {
            //返回原数列
        }

    } else {
        //找到B的位置
        for (int i = 0; i < newLen; i++) {
            if (colTemp[i] == newInterval[1]) {
                rightPos = i;
                break;
            }
        }
        // A最小
        if (leftPos == 0) {
            if (rightPos == intervalsSize) {
                //返回[A,B]
            } else if (rightPos == 0) {
            } else {
                //根据B具体的位置进行处理
            }
        }
    }

#endif
    return res;
}
