/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-09 14:35:23
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//第一反应：二叉树、动态规划、数学法，自己没写出来
//以下为动态规划题解：
int uniquePaths(int m, int n) {
    //首先将每个格子赋予0，注意边界只能为1
    int f[m][n];
    for (int i = 0; i < m; ++i) {
        f[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        f[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            //当前格的路径总数等于其左侧和上侧两格之和
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}

//下述为数学法
/**
 * 机器人需要向下走n-1次，向右走m-1次
 * 因此需要执行m+n-2种不同的方式
 * 因此只需要在m+n-2挑出m-1次即为总路径数
 * 写出这段的人贼聪明
 */
int uniquePaths(int m, int n) {
    long long res = 1;
    for (int x = n, y = 1; y < m; ++x, ++y) {
        res = res * x / y;
    }
    return res;
}
