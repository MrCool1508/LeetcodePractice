/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-14 16:25:25
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <cstdbool>
//模拟暴力解
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* res;
    if (0 == nums1Size) {
        *returnSize = 0;
        return NULL;
    } else if (0 == nums2Size) {
        res = malloc(nums1Size * sizeof(int));
        memset(res, -1, nums1Size * sizeof(int));
        *returnSize = nums1Size;
        return res;
    }

    *returnSize    = nums1Size;
    res            = malloc(nums1Size * sizeof(int));
    bool findFlag  = false;
    bool findEqual = false;
    for (int i = 0; i < nums1Size; i++) {
        findFlag  = false;
        findEqual = false;
        for (int j = 0; j < nums2Size; j++) {
            if (nums2[j] == nums1[i]) {
                findEqual = true;
                continue;
            }
            if (findEqual && nums2[j] > nums1[i]) {
                findFlag = true;
                res[i]   = nums2[j];
                break;
            }
        }
        if (!findFlag) {
            res[i] = -1;
        }
    }
    return res;
}
//快慢指针
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* res;
    if (0 == nums1Size) {
        *returnSize = 0;
        return NULL;
    } else if (0 == nums2Size) {
        res = malloc(nums1Size * sizeof(int));
        memset(res, -1, nums1Size * sizeof(int));
        *returnSize = nums1Size;
        return res;
    }

    *returnSize = nums1Size;
    res         = malloc(nums1Size * sizeof(int));
    int* n1Ptr  = nums1;
    int* n2Ptr  = nums2;
    int* rePtr  = res;
    int* tpPtr  = nums2;
    int  resCnt = nums2Size - 1;
    for (int i = 0; i < nums1Size; i++) {
        while (*n2Ptr < *n1Ptr && resCnt) {
            *n2Ptr++;
            resCnt--;
        }
        if (resCnt == 0) {
            /* code */
        }

        for (int j = 0; j < nums2Size; j++) {
            printf("%d | %d | %d\r\n", *n1Ptr, *n2Ptr, *rePtr);
            if (*n2Ptr == *n1Ptr) {
                tpPtr = n2Ptr;
            }
        }
        *rePtr++;
        *n1Ptr++;
    }
    return res;
}
