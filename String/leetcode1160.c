/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-09 17:18:16
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int countCharacters(char** words, int wordsSize, char* chars) {
    int res = 0;
    //[a,b]，a为字符串长度，b为是否出现在字母表中
    int** lenIn = (int**)malloc(wordsSize * sizeof(int*));
    for (int i = 0; i < wordsSize; i++) {
        lenIn[i]    = (int*)malloc(2 * sizeof(int));
        lenIn[i][0] = strlen(words[i]);

        for (int j = 0; i < len; i++) {
            /* code */
        }
    }

    return res;
}
