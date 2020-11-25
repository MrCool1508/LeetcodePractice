/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-24 00:18:07
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * @name: findBridge
 * @brief: 根据桥头桥尾值，找下一块板砖进行拼接，直至最后一块板砖大于等于桥尾值停止寻找。endNum>=startNum
 * @param {*}
 * @retval: none
 */
int findBridge(int** clips, int clipsSize, int* clipsColSize, int cnt, int startNum, int endNum) {
    int temp    = 0;
    int findRes = 0;    //是否能找到下一块砖
    for (int i = 0; i < clipsSize; i++) {
        if ((clips[i][0] <= startNum) && (clips[i][1] > startNum)) {
            if (temp < clips[i][1]) {
                temp = clips[i][1];    //找到最大值
            }
            findRes = 1;
        }
    }
    if (!findRes) {
        return -1;    //如果找不到下一块砖，直接返回-1
    } else {
        cnt++;                   //将砖的数量加一
        if (temp >= endNum) {    //判断当前砖是否达到桥尾
            return cnt;          //是，返回砖的数量
        } else {
            return findBridge(clips, clipsSize, clipsColSize, cnt, temp, endNum);    //否，查找下一块砖
        }
    }
}
/**
 * 算法分析：
 * + 输入：一系列的数组，以及需要切割的时长
 * + 输出：需要涵盖时长的数组段
 * + 达成：
 *      + 数组中最小的数应该为0；
 *      + 数组中最大的数应该大于等于时长；
 *      + 假设，最小数的数字对为（0，t1），最大数对为（t2，tmax）
 *        则，数组中其他数应该存在t<=t1 && t>=t2
 *      + 考虑到题目要求最少次数拼接，因此，t1应该找最大，t2应该找最小
 *      + 可以考虑拼接法，通过最小数对的t1，利用递归，开始查找下一数对，不断拼接至结果。
 *
 */
int videoStitching(int** clips, int clipsSize, int* clipsColSize, int T) {
    int res       = 0;
    int startFlag = 0;
    int endFlag   = 0;
    //特殊情况先过滤
    for (int i = 0; i < clipsSize; i++) {
        if (clips[i][0] == 0) {
            startFlag = 1;
        }
        if (clips[i][1] >= T) {
            endFlag = 1;
        }
        if ((clips[i][0] == 0) && (clips[i][1] >= T)) {
            res = 1;
            return res;
        }
    }

    if (startFlag && endFlag) {
        res = findBridge(clips, clipsSize, clipsColSize, res, 0, T);
        return res;
    } else {
        //不满足的直接return -1表示无法拼接
        res = -1;
        return res;
    }
}
