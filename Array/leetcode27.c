/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-08 15:31:07
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//没快到哪儿去
int removeElement(int* nums, int numsSize, int val) {
    int cntTemp = numsSize;

    for (int i = 0; i < cntTemp; i++) {
        if (val == nums[i]) {
            cntTemp--;
            while (val == nums[cntTemp]) {
                // printf("res[%d]:%d\r\n", cntTemp, nums[cntTemp]);
                if (cntTemp == i) break;
                cntTemp--;
                if (cntTemp < 0) return 0;
            }
            nums[i]       = nums[cntTemp];
            nums[cntTemp] = 0;
        }
    }
    return cntTemp;
}
//贼傻逼的操作
int removeElement(int* nums, int numsSize, int val) {
    int cntTemp  = numsSize;
    int numsTemp = nums[0];
    int cnt      = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (val == nums[i]) {
            cnt--;
        }
    }

    for (int i = 0; i < cntTemp; i++) {
        if (val == nums[i]) {
            cntTemp--;
            while (val == nums[cntTemp]) {
                // printf("res[%d]:%d\r\n", cntTemp, nums[cntTemp]);
                if (cnt == cntTemp) break;
                cntTemp--;
                if (cntTemp < 0) {
                    return 0;
                }
            }
            nums[i]       = nums[cntTemp];
            nums[cntTemp] = 0;
        }
    }
    return cnt;
}
//让我们学习一下题解——双指针
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
//题解二
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = numsSize;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            n--;    // reduce array size by one
        } else {
            i++;
        }
    }
    return n;
}
//题解三（题解一的简化版本）
int removeElement(int* nums, int numsSize, int val) {
    int size = 0;
    int i    = 0;

    for (i = 0; i <= numsSize - 1; i++) {
        if (nums[i] != val) {
            nums[size++] = nums[i];    // ignore the same
        }
    }
    return size;
}
