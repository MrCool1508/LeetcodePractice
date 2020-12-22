/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-22 18:11:54
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//这道题的本质应该是判断所给数组中最大能容纳多少个相邻数
//值得注意的是，不能仅仅只看i\i+1和i+2，应该顾及i+3
//当可以插入相邻数时，cnt++；当cnt超过n时，break并直接return true
//每三个连续0可以种一朵花
//下述code忽略了特殊情况
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (0 == n) return true;
    int cnt = 0;
    //特殊情况，size=1
    if (flowerbedSize == 1) {
        if (!flowerbed[0])
            return true;
        else
            return false;
    }
    //特殊情况，size=2
    if (flowerbedSize == 2) {
        if (2 == n)
            return false;
        else if (!flowerbed[0] && !flowerbed[1]) {
            return true;
        } else
            return false;
    }
    //特殊情况，size=3
    if (flowerbedSize == 3) {
        if (3 == n) {
            return false;
        } else {
            if (flowerbed[1]) {
                return false;
            } else {
                if (!flowerbed[0]) {
                    cnt++;
                }
                if (!flowerbed[2]) {
                    cnt++;
                }
            }
        }
        return cnt >= n;
    }
    //一般情况
    if (!flowerbed[0] && !flowerbed[1]) {
        cnt++;
        flowerbed[0] = 1;
    }

    for (int i = 1; i < flowerbedSize - 1; i++) {
        if (!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i + 1]) {
            cnt++;
            flowerbed[i] = 1;
        }
    }
    return cnt >= n;
}
//又来抄作业了，贪心法
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i, total = 0;
    if (n == 0) return true;
    if (flowerbedSize == 1 && !flowerbed[0]) return true;
    //特殊头
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
        flowerbed[0] = 1;
        total++;
    }
    //特殊尾
    if (flowerbed[flowerbedSize - 1] == 0 && flowerbed[flowerbedSize - 2] == 0) {
        flowerbed[flowerbedSize - 1] = 1;
        total++;
    }
    //正常循环，每三个能置位1个
    for (i = 1; i < flowerbedSize - 1; i++) {
        if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            total++;
        }
    }
    return total >= n;
}
