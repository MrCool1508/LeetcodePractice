/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-10 10:37:01
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int myCpr(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
//交换两个数
void swap(int a, int b) {
    int temp;
    temp = b;
    b    = a;
    a    = temp;
}
void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int flag   = 0;    //是否存在下一个更大的排列，是为1，否为0
    int maxPos = 0;
    //执行查找,逆向滑动窗口
    int* endPtr  = nums[numsSize - 1];    //指向最后一个元素
    int* ptr     = nums[numsSize - 2];    //倒数第二个数开始
    int  cnt     = 1;
    int* p_slow  = nums[numsSize - 1];
    int* p_fast  = nums[numsSize - 2];
    int  sizeCnt = numsSize;

    for (int i = 0; i < numsSize; i++) {
        if (*p_slow > *p_fast) {
            swap(*p_slow, *p_fast);
            break;
        }
    }

    //如果不存在
    if (!flag) {
        qsort(nums, numsSize, sizeof(int), myCpr);
    }
}
