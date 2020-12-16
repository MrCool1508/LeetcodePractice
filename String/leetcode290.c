/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-16 20:35:32
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//模式匹配，模拟法和散列表应该都能解决
//模拟法：strtok进行断词,strcmp比较两个字符串
bool wordPattern(char* pattern, char* s) {
    int   patternLen = strlen(pattern);
    int   s_len      = strlen(s);
    char* s_temp     = (char*)malloc((s_len + 1) * sizeof(char));
    memcpy(s_temp, s, (s_len + 1));
    const char seperate[2] = " ";
    char*      token       = strtok(s_temp, seperate);
    int        wordCnt     = 0;
    char**     wordDic     = (char**)malloc(patternLen * sizeof(char*));
    wordDic[0]             = token;
    char* wordDicPtr       = wordDic[0];
    while (token != NULL) {
        *wordDicPtr++;
        token      = strtok(NULL, seperate);
        wordDicPtr = token;
        wordCnt++;
    }
    printf("%d | %d\r\n", wordCnt, patternLen);
    if (wordCnt != patternLen) {
        return false;
    }
    for (int i = 0; i < patternLen; i++) {
        for (int j = i + 1; j < patternLen; j++) {
            if (pattern[i] == pattern[j]) {
                if (strcmp(wordDic[i], wordDic[j])) {
                    return false;
                }
            }
            if (0 == strcmp(wordDic[i], wordDic[j])) {
                if (pattern[i] != pattern[j]) {
                    return false;
                }
            }
        }
    }

    return true;
}
