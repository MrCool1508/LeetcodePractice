/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-21 12:39:54
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//盲猜贪心算法，试试
int minCostClimbingStairs(int* cost, int costSize) {
    int res    = 0;
    int curPos = 0;
    if (costSize <= 3) {
        res = cost[0] > cost[1] ? cost[1] : cost[0];
    } else {
        //没写出来...
    }

    return res;
}
//题解：动态规划
int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize + 1];
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= costSize; i++) {
        dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[costSize];
}

//题解：动态规划+滚动数组
int minCostClimbingStairs(int* cost, int costSize) {
    int prev = 0, curr = 0;
    for (int i = 2; i <= costSize; i++) {
        int next = fmin(curr + cost[i - 1], prev + cost[i - 2]);
        prev     = curr;
        curr     = next;
    }
    return curr;
}
