/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-16 22:18:40
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @name: createTargetArray
 * @brief: leetcode1389.题目已知numSize == indexSize
 * @param {int* nums, int numsSize, int* index, int indexSize, int* returnSize}
 * @retval: none
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    // printf("%d | %d\r\n",numsSize, indexSize);

    int  temp_1     = 0;
    int  temp_2     = 0;
    int  cnt        = 0;
    int* res        = (int*)calloc(numsSize, sizeof(int));
    int* occupyFlag = (int*)calloc(numsSize, sizeof(int));    //有数字则为1，无数字，则为0
    *returnSize     = numsSize;
    for (int i = 0; i < indexSize; i++) {
        if (occupyFlag[*(index + i)] == 0) {
            res[*(index + i)]        = nums[i];    //当前res无值，直接将值放入对应位置
            occupyFlag[*(index + i)] = 1;          //标记当前res有值
        } else {
            // printf("!!!i:%d!!!\r\n",i);
            //当前位置有值
            temp_1            = res[*(index + i)];    //将位置腾空
            res[*(index + i)] = nums[i];              //将值放入对应位置

            for (int j = *(index + i) + 1; j < numsSize; j++) {
                if (occupyFlag[j] == 0) {
                    res[j]        = temp_1;    //当前res无值，直接将值放入对应位置
                    occupyFlag[j] = 1;         //标记当前res有值
                    // printf("???i:%d | res:%d???\r\n",i,res[*(index + i) + 1]);
                } else {
                    //当前位置有值
                    temp_2 = res[j];    //将位置腾空
                    res[j] = temp_1;    //将值放入对应位置
                    temp_1 = temp_2;
                    // printf("i:%d,j:%d,tp1:%d,tp2:%d\r\n",i,j,temp_1,temp_2);
                }
            }
        }
    }
    free(occupyFlag);
    return res;
}
