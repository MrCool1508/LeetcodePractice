int main(int argc, char const* argv[]) {
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @name: 方法名称
 * @brief: leetcode728
 * @param {type}
 * @retval: none
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int  cnt     = right - left + 1;
    int  resCnt  = 0;
    int  temp_0  = left;    //用于存储移位的值
    int  temp_1  = left;    //用于存放当前值
    int  flag    = 0;       //标记满足需求
    int* resTemp = (int*)calloc(cnt, sizeof(int));
    int  inLeft  = left;
    int  inRight = right;
    int* res;
    if (right < 10) {
        res = (int*)calloc(cnt, sizeof(int));
        for (int i = 0; i < cnt; i++) {
            res[i] = left++;
        }
        resCnt = cnt;
    } else if (right >= 10) {
        for (int i = 0; i < cnt; i++, temp_1++) {
            temp_0 = left + i;
            while (temp_0 > 0) {
                if ((temp_0 % 10) != 0) {
                    // printf("tp1:%d | (tp0%10):%d\r\n", temp_1, (temp_0 % 10));
                    if ((temp_1 % (temp_0 % 10)) == 0) {
                        temp_0 /= 10;
                        flag = 1;
                        // printf("tp1: %d| tp0:%d\r\n", temp_0, temp_1);
                    } else {
                        flag = 0;
                        break;
                    }
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                resCnt++;
                *(resTemp + i) = 1;
                printf("RT[%d]:%d,resCnt:%d\r\n", i, *(resTemp + i), resCnt);
            }
            // if (i == 5) {
            //     printf("RT[5]:%d\r\n", *(resTemp + i));
            // }
        }
        res   = (int*)calloc(resCnt, sizeof(int));
        int j = 0;

        for (int i = 0; i < cnt; i++) {
            if (resTemp[i] == 1) {
                res[j] = inLeft;
                j++;
                // printf("---------%3d | %3d   %2d\r\n",res[j], inLeft,i);
            }
            // printf("--------- %3d   %2d\r\n", inLeft,i);
            printf("---------%3d | %3d   %2d\r\n", res[j - 1], inLeft, i);
            inLeft++;
        }
    }
    free(resTemp);
    *returnSize = resCnt;
    return res;
}
