/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-29 21:32:30
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int myCpr(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int lastStoneWeight(int *stones, int stonesSize) {
    if (1 == stonesSize) {
        return stones[0];
    }
    if (2 == stonesSize) {
        if (stones[0] == stones[1]) {
            return 0;
        } else {
            return abs(stones[0] - stones[1]);
        }
    }
    qsort(stones, stonesSize, sizeof(int), myCpr);
    int temp     = 0;
    int sizeTemp = stonesSize;
    int cnt      = 0;
    for (int i = sizeTemp - 1; i >= 1; i--) {
        if (stones[i] == stones[i - 1]) {
            stones[i]     = 0;
            stones[i - 1] = 0;
            i--;
            cnt += 2;

        } else {
            temp          = stones[i] - stones[i - 1];
            stones[i]     = 0;
            stones[i - 1] = temp;
            cnt++;
            qsort(stones, sizeTemp - cnt, sizeof(int), myCpr);
        }

        if (0 == stones[2]) {
            break;
        }
    }
    if (stones[0] == stones[1]) {
        return 0;
    } else {
        return abs(stones[0] - stones[1]);
    }
}
