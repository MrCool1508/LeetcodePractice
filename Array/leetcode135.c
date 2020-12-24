/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-24 14:53:23
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//首先保证每个人至少1个糖果
//相邻的，评分高的孩子拿到更多的糖果。
/*
 * 特殊情况，如果i i+1 i+2 i+3 的评分分别为：
 * 0 1 1 1，则只需要5颗，第二个孩子多1颗
 * 1 1 1 1，只需要4颗，每个人1颗
 * 0 1 1 0，需要6颗，中间两个孩子各多1颗
 * 0 1 1 2，也是6颗，第一个1和最后一个孩子个多1颗
 * 由此可见，分糖果应该由它的左侧和它的右侧来决定当前孩子能获得几颗糖果
 * */
//这道题有点像山顶问题，存在上坡和下坡的不同情况

//下面方法无法通过
int candy(int* ratings, int ratingsSize) {
    int res = ratingsSize;
    if (ratingsSize <= 1) {
        return res;
    } else if (ratingsSize == 2) {
        if (ratings[0] == ratings[1])
            return res;
        else
            return res + 1;
    }

    int* candyCnt = calloc(ratingsSize, sizeof(int));
    int* peak     = ratings;    //山顶
    int* valley   = ratings;    //山谷
    for (int i = 0; i < ratingsSize - 1; i++) {
        if (ratings[i] < ratings[i + 1]) {
            *peak = ratings + i + 1;
        }
    }

    return res;
}
printf("[%d]:%d\r\n", i, candyCnt[i]);
//抄题解
//这个思路不错，在递减序列时，小的评分反而加的多
//（只看总数不看单个，是可以直接这样操作的）
int candy(int* ratings, int ratingsSize) {
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] >= ratings[i - 1]) {
            dec = 0;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            ret += pre;
            inc = pre;
        } else {
            dec++;
            if (dec == inc) {
                dec++;
            }
            ret += dec;
            pre = 1;
        }
    }
    return ret;
}
//两次for循环
int candy(int* ratings, int ratingsSize) {
    int left[ratingsSize];
    //左规则，循环
    for (int i = 0; i < ratingsSize; i++) {
        if (i > 0 && ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1;
        }
    }
    //右规则
    int right = 0, ret = 0;
    for (int i = ratingsSize - 1; i >= 0; i--) {
        if (i < ratingsSize - 1 && ratings[i] > ratings[i + 1]) {
            right++;
        } else {
            right = 1;
        }
        ret += fmax(left[i], right);
    }
    return ret;
}
