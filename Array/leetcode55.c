/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-24 15:41:24
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdbool.h>
/**
 * @name: jump
 * @brief: 用于跳跳跳
 * @param {*}
 * @retval: none
 */
bool jump(int* nums, int numsSize, int currentPos, int jumpStep) {
    bool res = false;
    if ((currentPos + jumpStep) >= numsSize) {
        res = true;    //可以直接跳到末尾
        return res;
    } else if ((currentPos + jumpStep) <= 0) {
        res = false;    //往回跳，且为NULLor原始位置
        return res;
    } else if ((jumpStep == 0) && (currentPos < numsSize)) {
        res = false;    //原地不跳
        return res;
    } else {
        currentPos += jumpStep;                                           //更新当前位置
        return jump(nums, numsSize, currentPos, nums[currentPos - 1]);    //跳向下一位置
    }
}
bool canJump(int* nums, int numsSize) {
    bool res = false;
    res      = jump(nums, numsSize, 1, nums[0]);
    return res;
}
