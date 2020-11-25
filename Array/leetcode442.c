/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), myCpr);    //因为元素要么出现一次，要么出现两次，所以先排序
    int  cnt     = 0;
    int* p       = nums;
    int* p_delet = nums;
    for (int i = 0; i < numsSize - 1; i++) {
        if (*p == *(p + 1)) {
            *p_delet = *p;
            i++;
            cnt++;
            p += 2;
            p_delet++;
            continue;
        }
        *p++;
    }
    *returnSize = cnt;
    return nums;
}
