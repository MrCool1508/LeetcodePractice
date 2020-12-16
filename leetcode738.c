/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-15 21:29:09
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int monotoneIncreasingDigits(int N) {
    if (0 == N) {
        return 0;
    } else {
        int res = N - 1;
        if (N <= 10) return res;
        int cnt = 0;
        while (res) {
            res /= 10;
            cnt++;
        }
        int *tp    = malloc(cnt * sizeof(int));
        int  cntTp = cnt;
        res        = N - 1;
        while (res) {
            tp[cnt - 1] = res % 10;
            printf("%d\r\n", tp[cnt - 1]);
            res /= 10;
            cnt--;
        }
        //从末位往前计算
        cnt = cntTp;
        for (int i = cnt - 1; i > 0; i--) {
            if (tp[i] < tp[i - 1]) {
                tp[i - 1] = tp[i]
            }
        }

        return res;
    }
}
