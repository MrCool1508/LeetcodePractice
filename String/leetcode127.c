/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-05 20:38:16
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int res      = 0;
    int haveWord = 1;
    for (int i = 0; i < wordListSize; i++) {
        haveWord = strcmp(endWord, wordList[i]);
        if (!haveWord) {
            break;
        }
    }
    if (haveWord) return res;
    int str_len = strlen(beginWord);
    return res;
}
