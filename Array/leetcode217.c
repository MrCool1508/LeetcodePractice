/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-13 11:15:26
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//整数数组...没说是0-9的数字
//可以qsort，如果出现相邻相同则false
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), myCpr);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}
//方法二：哈希查找，以下参考题解
struct hashTable {
    int            key;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable* set = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums + i, tmp);
        //不同的插入表，相同的直接返回
        if (tmp == NULL) {
            tmp      = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}
