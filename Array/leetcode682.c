/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-31 11:48:57
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-31 11:48:57
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int string2Num(char* str) {
    int strLen     = strlen(str);
    int res        = 0;
    int nativeFlag = 0;

    for (int i = 0; i < strLen; i++) {
        if ((nativeFlag == 0) && (str[0] == '-')) {
            nativeFlag = 1;
            continue;
        }
        // printf("r:%d\r\n",res);
        res = res * 10 + (str[i] - 48);
    }
    if (nativeFlag) res = -res;
    // printf("----strLen:%d, res:%d----\r\n", strLen, res);
    return res;
}

int calPoints(char** ops, int opsSize) {
    int  res      = 0;
    int  lastNum  = 0;
    int  lastTemp = 0;
    int* sum      = (int*)calloc(opsSize, sizeof(int));
    int* p        = sum;
    // printf("???%d\r\n",string2Num(ops[0]));
    for (int i = 0; i < opsSize; i++) {
        switch (ops[i][0]) {
            case '+':
                *p = *(p - 1) + *(p - 2);
                *p++;
                break;
            case 'C':
                *p--;
                *p = 0;
                break;
            case 'D':
                *p = *(p - 1) * 2;
                *p++;
                break;
            default:
                *p = string2Num(ops[i]);
                // printf("sum[%d]:%d\r\n",i,sum[i]);
                *p++;
                break;
        }
    }
    for (int i = 0; i < opsSize; i++) {
        res += sum[i];
        // printf("res:%d,sum[%d]:%d\r\n",res, i,sum[i]);
    }
    return res;
}
