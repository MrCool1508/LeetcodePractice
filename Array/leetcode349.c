/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 12:58:44
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int  cnt      = 0;
    int  sameFlag = 0;
    int  maxSize  = (nums1Size >= nums2Size) ? nums1Size : nums2Size;
    int* resTemp  = (int*)calloc(maxSize, sizeof(int));
    int* p        = resTemp;

    if ((!nums1Size) || (!nums2Size)) {
        *returnSize = 0;
        return resTemp;
    } else {
        for (int i = 0; i < nums1Size; i++) {
            for (int j = 0; j < nums2Size; j++) {
                if (nums1[i] == nums2[j]) {
                    //如果两个值相等，则与结果数组比较
                    for (int k = 0; k < cnt; k++) {
                        if (resTemp[k] == nums2[j]) {
                            sameFlag = 1;
                            break;    //跳出与结果数组比较循环
                        } else {
                            sameFlag = 0;
                        }
                    }
                    if (!sameFlag) {
                        //如果都没有该值，则执行：
                        *p = nums2[j];
                        *p++;
                        cnt++;
                    }
                    break;
                }
            }
        }
        *returnSize = cnt;
        return resTemp;
    }
}
