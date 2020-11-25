/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-08 12:43:53
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

/* 当天价格大于前一天价格，前一天买入，当天卖出，利润累加 */
int maxProfit(int* prices, int pricesSize) {
    int res = 0;
    for (int i = 1; i < pricesSize; i++) {
        res += fmax(0, prices[i] - prices[i - 1]);
    }
    return res;
}
