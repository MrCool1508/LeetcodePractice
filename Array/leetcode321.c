/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-02 14:09:03
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//没啥思路，查看题解，关键词“单调栈”
//这里题有几个需要关注的知识点。 一个是如何从单一数组中取出k个数，在不改变相对顺序的情况下使其最大，这是典型的单调栈的思路。
//抄一遍题解。
/**
 * @name: 方法名称
 * @brief: 方法功能描述
 * @param {*}
 * @retval: none
 */
int compare(int* subseq1, int subseq1Size, int index1, int* subseq2, int subseq2Size, int index2) {
    while (index1 < subseq1Size && index2 < subseq2Size) {
        int difference = subseq1[index1] - subseq2[index2];
        if (difference != 0) {
            return difference;
        }
        index1++;
        index2++;
    }
    return (subseq1Size - index1) - (subseq2Size - index2);
}
/**
 * @name: 方法名称
 * @brief: 方法功能描述
 * @param {*}
 * @retval: none
 */
int* merge(int* subseq1, int subseq1Size, int* subseq2, int subseq2Size) {
    if (subseq1Size == 0) {
        return subseq2;
    }
    if (subseq2Size == 0) {
        return subseq1;
    }
    int  mergeLength = subseq1Size + subseq2Size;
    int* merged      = malloc(sizeof(int) * (subseq1Size + subseq2Size));
    int  index1 = 0, index2 = 0;
    for (int i = 0; i < mergeLength; i++) {
        if (compare(subseq1, subseq1Size, index1, subseq2, subseq2Size, index2) > 0) {
            merged[i] = subseq1[index1++];
        } else {
            merged[i] = subseq2[index2++];
        }
    }
    return merged;
}
/**
 * @name: 方法名称
 * @brief: 方法功能描述
 * @param {*}
 * @retval: none
 */
int* MaxSubsequence(int* nums, int numsSize, int k) {
    int* stack = malloc(sizeof(int) * k);
    memset(stack, 0, sizeof(int) * k);
    int top    = -1;
    int remain = numsSize - k;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        while (top >= 0 && stack[top] < num && remain > 0) {
            top--;
            remain--;
        }
        if (top < k - 1) {
            stack[++top] = num;
        } else {
            remain--;
        }
    }
    return stack;
}
/**
 * @name: 方法名称
 * @brief: 交换两个数字
 * @param {*}
 * @retval: none
 */
void swap(int** a, int** b) {
    int* tmp = *a;
    *a = *b, *b = tmp;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    // int* maxSubsequence = malloc(sizeof(int) * k);
    // memset(maxSubsequence, 0, sizeof(int) * k);
    int* maxSubsequence = calloc(k, sizeof(int));
    *returnSize         = k;
    int start = fmax(0, k - nums2Size), end = fmin(k, nums1Size);
    for (int i = start; i <= end; i++) {
        int* subseq1           = MaxSubsequence(nums1, nums1Size, i);
        int* subseq2           = MaxSubsequence(nums2, nums2Size, k - i);
        int* curMaxSubsequence = merge(subseq1, i, subseq2, k - i);
        if (compare(curMaxSubsequence, k, 0, maxSubsequence, k, 0) > 0) {
            swap(&curMaxSubsequence, &maxSubsequence);
        }
    }
    return maxSubsequence;
}
