/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-19 16:10:38
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* res  = (int*)calloc(pricesSize, sizeof(int));    //存放结果
    int  flag = 0;                                        //用于标记是否有折扣
    //最后一件商品永远没有折扣
    res[pricesSize - 1] = prices[pricesSize - 1];
    //其他商品计算
    for (int i = 0; i <= pricesSize - 1; i++) {
        flag = 0;
        for (int j = i + 1; j < pricesSize; j++) {
            // printf("i:%d, j:%d | be:%d | af:%d\r\n",i,j,*(prices + i) ,*(prices + j) );
            if (*(prices + j) <= (*(prices + i))) {
                *(res + i) = *(prices + i) - *(prices + j);
                // printf("--res:%d---\r\n",*(res + i));
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
        if (flag) {
            *(res + i) = *(prices + i);    //没有折扣则直接将原价格复制到结果
        }
    }

    *returnSize = pricesSize;
    return res;
}
