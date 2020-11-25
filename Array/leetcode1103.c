/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-03 12:06:21
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize) {
    int* res    = (int*)calloc(num_people, sizeof(int));
    *returnSize = num_people;
    int lastNum = 0;
    while (candies) {
        for (int i = 0; i < num_people; i++) {
            candies -= (lastNum + 1);
            if (candies < 0) {
                candies += (lastNum + 1);
                res[i] += candies;
                candies = 0;
                break;
            } else {
                res[i] += (lastNum + 1);
            }
            lastNum++;
        }
    }

    return res;
}
