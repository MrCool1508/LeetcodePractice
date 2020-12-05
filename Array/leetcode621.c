/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-05 14:50:54
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//桶思想
int leastInterval(char* tasks, int tasksSize, int n) {
    if (0 == n) {
        return tasksSize;
    }
    int res          = 0;
    int alphaDic[26] = {0};
    int maxNum[2]    = {0};
    //最多任务数若大于等于maxTaskLimit，则会出现等待时间
    //若最多任务数大于taskSize/2也会出现等待时间。
    int maxTaskLimit = tasksSize / (n + 1) + 1;
    printf("---------%d\r\n", maxTaskLimit);
    for (int i = 0; i < tasksSize; i++) {
        alphaDic[tasks[i] - 'A']++;
        if (alphaDic[tasks[i] - 'A'] > maxNum[0]) {
            maxNum[0] = alphaDic[tasks[i] - 'A'];
            maxNum[1] = tasks[i] - 'A';
        }
    }
    int  resSize = maxNum[0] * (n + 1);
    int* resTemp = calloc(resSize, sizeof(int));
    int  cnt     = 1;
    resTemp[0]   = 1;
    printf("%d_", resTemp[0]);
    for (int i = 1; i < resSize; i++) {
        if (i == cnt * (n + 1)) {
            resTemp[i] = 1;
            printf("%d_", resTemp[i]);
            alphaDic[maxNum[1]]--;
            cnt++;
        } else {
            printf("0_");
        }
    }
    printf("\r\n");
    int availablePos = 1;
    for (int i = 0; i < 25; i++) {
        while (alphaDic[i] != 0) {
            for (int j = availablePos; j < resSize; j++) {
                if (i == cnt * (n + 1)) {
                    resTemp[i] = 1;
                    printf("%d_", resTemp[i]);
                    alphaDic[maxNum[1]]--;
                    cnt++;
                } else {
                    printf("0_");
                }
            }
        }
    }

    return res;
}
//又来抄题解的作业了
int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < tasksSize; ++i) {
        ++freq[tasks[i] - 'A'];
    }

    // 任务总数
    int m = 0;
    // nextValid为最早可执行的时间
    // rest为剩余待执行的次数
    int nextValid[26], rest[26];
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            nextValid[m] = 1;
            rest[m++]    = freq[i];
        }
    }

    int time = 0;
    for (int i = 0; i < tasksSize; ++i) {
        ++time;
        int minNextValid = INT_MAX;
        for (int j = 0; j < m; ++j) {
            if (rest[j]) {
                minNextValid = fmin(minNextValid, nextValid[j]);
            }
        }
        time     = fmax(time, minNextValid);
        int best = -1;
        for (int j = 0; j < m; ++j) {
            if (rest[j] && nextValid[j] <= time) {
                if (best == -1 || rest[j] > rest[best]) {
                    best = j;
                }
            }
        }
        nextValid[best] = time + n + 1;
        --rest[best];
    }

    return time;
}
