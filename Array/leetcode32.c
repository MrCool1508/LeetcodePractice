/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-01 11:01:37
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//暴力解法，时间复杂度为O(n)
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res    = malloc(2 * sizeof(int));
    res[0]      = -1;
    res[1]      = -1;
    *returnSize = 2;
    if (numsSize < 1) {
        return res;
    } else if (1 == numsSize) {
        if (target == nums[0]) {
            res[0] = 0;
            res[1] = 0;
            return res;
        }
    } else {
        for (int i = 0; i < numsSize; i++) {
            if (target == nums[i]) {
                if (-1 == res[0]) {
                    res[0] = i;
                } else {
                    res[1] = i;
                }
            }
        }
        if (-1 == res[1] && -1 != res[0]) {
            res[1] = res[0];
        }
        return res;
    }
    return res;
}
//仔细阅读题目，发现题目已告知，数组序列为升序。因此应该考虑
//用二分查找法
//以下非官方题解：

//先判读有没有这个数字
int binary_search(int* nums, int n, int target) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        //知识点：
        //右移运算符>>,运算结果正好能对应一个整数的二分之一值。
        //这就正好能代替数学上的除2运算，但是比除2运算要快。
        // mid = (left + right) >> 1相当于mid = (left + right) / 2
        mid = (left + right) >> 1;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
//查找第一个大于等于它的数
int binary_search1(int* nums, int n, int target) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (nums[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return l == n ? -1 : l;
}
//查找第一个大于等于它的数
int binary_search2(int* nums, int n, int target) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (nums[mid] <= target)
            l = mid;
        else
            r = mid - 1;
        printf("l:%d,r:%d\r\n", l, r);
    }
    return l;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 3);
    int  t, t1, t2 = 0;
    t = binary_search(nums, numsSize, target);
    if (t == -1) {
        arr[0] = arr[1] = -1;
        *returnSize     = 2;
        return arr;
    }
    t1          = binary_search1(nums, numsSize, target);
    t2          = binary_search2(nums, numsSize, target);
    arr[0]      = t1;
    arr[1]      = t2;
    *returnSize = 2;
    return arr;
}
//以下，官方题解：
/**
 * @name: 方法名称
 * @brief: 在nums数组中二分查找target的位置。
 *         如果lower为true，则查找第一个大于等于target的下标。
 *         否则查找第一个大于target 的下标。
 * @param {*}
 * @retval: none
 */
// lower用于做开关
int binarySearch(int* nums, int numsSize, int target, bool lower) {
    int left = 0, right = numsSize - 1, ans = numsSize;
    while (left <= right) {
        // int mid = (left + right) / 2;
        int mid = (left + right) >> 1;
        //第一个条件用于查找最后一个目标数的位置
        //第二个条件用于查找第一个出现目标数的位置
        if (nums[mid] > target || (lower && nums[mid] >= target)) {
            right = mid - 1;
            ans   = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int  leftIdx  = binarySearch(nums, numsSize, target, true);
    int  rightIdx = binarySearch(nums, numsSize, target, false) - 1;
    int* ret      = malloc(sizeof(int) * 2);
    *returnSize   = 2;
    //二次验证
    if (leftIdx <= rightIdx && rightIdx < numsSize && nums[leftIdx] == target && nums[rightIdx] == target) {
        ret[0] = leftIdx, ret[1] = rightIdx;
        return ret;
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}
