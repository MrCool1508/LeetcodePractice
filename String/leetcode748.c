/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-21 19:33:14
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

void words2alphaDic(char* s, int s_len, int* alphaDic) {
    for (int i = 0; i < s_len; i++) {
        alphaDic[s[i] - 'a']++;
    }
}

int processLic(char* s, int s_len, int* alphaDic) {
    int res = 0;
    for (int i = 0; i < s_len; i++) {
        if (s[i] < 'A')
            continue;
        else {
            if (s[i] >= 'a') {
                alphaDic[s[i] - 'a']++;
            } else {
                alphaDic[s[i] - 'A']++;
            }
            res++;
        }
    }
    return res;
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int alphaDic[26] = {0};
    int licLen       = strlen(licensePlate);
    int wordCnt      = 0;    //用于存放牌照中出现字母的个数
    //处理字符串牌照
    wordCnt = processLic(licensePlate, licLen, alphaDic);
    // printf("wc: %d\r\n", wordCnt);
    int  wordLen     = 0;                            //用于存放每个待比较字符串的长度
    int  compDic[26] = {0};                          //用于存放每个待比较字符串各个字母出现的次数
    int* rightWords  = calloc(1000, sizeof(int));    //用于标记满足条件的字符串，满足置为字符串长度，否则为0
    //将每个字符串都进行比较处理
    for (int i = 0; i < wordsSize; i++) {
        // printf("\r\n!!!!!!!%d-round", i);
        memset(compDic, 0, sizeof(int) * 26);
        wordLen = strlen(words[i]);    //获得当前字符串的长度
        if (wordLen < wordCnt) {
            rightWords[i] = 0;
            continue;
        } else {
            words2alphaDic(words[i], wordLen, compDic);
            for (int j = 0; j < 26; j++) {
                if (alphaDic[j] > 0) {
                    // printf("----aDic[%d]: %c, cmpDic[%d]: %d---",j , j+'a',j,compDic[j]);
                    if (alphaDic[j] > compDic[j]) {
                        rightWords[i] = 0;
                        break;
                    } else {
                        rightWords[i] = 1;
                    }
                    // printf("\r\n");
                }
            }
            if (rightWords[i] == 1) {
                rightWords[i] = wordLen;
                // printf("---%s\r\n",words[i]);
            }
        }
    }
    //最终的结果，找到最短补全词
    bool firstComp = false;    //首次进入的开关
    int  minLen    = 0;        //最短补全词长度
    int  minPos    = 0;        //最短补全词所在位置
    // printf("\r\n");
    for (int i = 0; i < wordsSize; i++) {
        if (rightWords[i] != 0) {
            //首次进入
            // printf("%s\r\n", words[i]);
            if (!firstComp) {
                firstComp = true;
                minLen    = rightWords[i];
                minPos    = i;
            }
            //比较是否为最短补全词
            if (rightWords[i] < minLen) {
                minLen = rightWords[i];
                minPos = i;
            }
        }
    }
    free(rightWords);
    char* res = words[minPos];    //存放最终结果
    return res;
}
