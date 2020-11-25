/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-23 11:22:55
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/** 方法一：傻办法，超出时间限制
 * 算法分析：
 * + 空间复杂度为O(n)
 * + 时间复杂度为O(n^2)
 **/
int multiplicative(int* nums, int numsSize) {
    int res = 1;
    for (int i = 0; i < numsSize; i++) {
        res *= *(nums + i);
    }
    return res;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res  = calloc(sizeof(int), numsSize);
    int  temp = 0;
    int  mult = 1;
    for (int i = 0; i < numsSize; i++) {
        temp        = *(nums + i);
        *(nums + i) = 1;
        *(res + i)  = multiplicative(nums, numsSize);
        *(nums + i) = temp;
    }

    *returnSize = numsSize;
    return res;
}
/** 方法二：前缀之积与后缀之积的乘积
 * 算法分析：
 * + 空间复杂度为O(n)
 * + 时间复杂度为O(n)
 **/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res  = calloc(sizeof(int), numsSize);
    int* lRes = calloc(sizeof(int), numsSize);
    int* rRes = calloc(sizeof(int), numsSize);

    *lRes                  = 1;
    *(rRes + numsSize - 1) = 1;
    //求前缀积数组
    for (int i = 1; i < numsSize; i++) {
        *(lRes + i) = *(lRes + i - 1) * (*(nums + i - 1));
        // printf("lRes:%d |", *(lRes+i));
    }
    // printf("\r\n");
    //求后缀积数组
    for (int i = numsSize - 1; i > 0; i--) {
        *(rRes + i - 1) = *(rRes + i) * (*(nums + i));
        // printf("rRes:%d |", *(rRes + i -1));
    }
    //    printf("\r\n");
    //求最终结果=前缀*后缀
    for (int i = 0; i < numsSize; i++) {
        *(res + i) = *(lRes + i) * (*(rRes + i));
        // printf("*lr:%8d,*rr:%8d, *r:%8d\r\n",*(lRes+i), *(rRes+i), *(res+i));
    }
    // printf("\r\n");

    *returnSize = numsSize;
    return res;
}
/** 方法二(优化一)：前缀之积与后缀之积的乘积
 * 算法分析：
 * + 空间复杂度为O(n)
 * + 时间复杂度为O(n)
 **/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res  = calloc(sizeof(int), numsSize);    //后缀积与最终结果复用
    int* lRes = calloc(sizeof(int), numsSize);
    //    int* rRes = calloc(sizeof(int), numsSize);

    *lRes                 = 1;
    *(res + numsSize - 1) = 1;
    //求前缀积数组
    for (int i = 1; i < numsSize; i++) {
        *(lRes + i) = *(lRes + i - 1) * (*(nums + i - 1));
        // printf("lRes:%d |", *(lRes+i));
    }
    // printf("\r\n");
    //求后缀积数组
    for (int i = numsSize - 1; i > 0; i--) {
        *(res + i - 1) = *(res + i) * (*(nums + i));
        *(res + i) *= *(lRes + i);
        // printf("rRes:%d |", *(rRes + i -1));
    }

    *returnSize = numsSize;
    return res;
}
/** 方法二(优化二)：前缀之积与后缀之积的乘积
 * 算法分析：
 * + 空间复杂度为O(1)
 * + 时间复杂度为O(n)
 **/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res  = calloc(sizeof(int), numsSize);    //后缀积与最终结果复用
    int  temp = 1;
    *res      = 1;
    //求前缀积数组
    for (int i = 1; i < numsSize; i++) {
        *(res + i) = *(res + i - 1) * (*(nums + i - 1));
    }
    //求后缀积数组
    for (int i = numsSize - 1; i >= 0; i--) {
        *(res + i) *= temp;
        temp *= *(nums + i);
    }

    *returnSize = numsSize;
    return res;
}
/** 方法二(进阶)：前缀之积与后缀之积的乘积
 * 算法分析：
 * + 空间复杂度为O(1)
 * + 时间复杂度为O(n)
 **/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = calloc(sizeof(int), numsSize);
    int  p = 1, q = 1;
    for (int i = 0; i < numsSize; i++) {
        res[i] = p;
        p *= nums[i];
    }
    for (int i = numsSize - 1; i > 0; i--) {
        q *= nums[i];
        res[i - 1] *= q;
    }
    *returnSize = numsSize;
    return res;
}
