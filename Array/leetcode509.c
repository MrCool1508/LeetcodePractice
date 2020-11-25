/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-09 17:03:00
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/*因为有重复计算，太慢了*/
int fib(int N) {
    if ((N == 0) || (N == 1)) {
        return N;
    } else {
        return fib(N - 1) + fib(N - 2);
    }
}

int fib(int N) {
    if (N == 0 || N == 1) return N;
    int a = 0, b = 1;    // a为f(N-1),b为f(N)或f(N-1)
    for (int i = 2; i <= N; i++) {
        b = a + b;
        a = b - a;
    }
    return b;
}
