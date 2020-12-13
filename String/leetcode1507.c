/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-13 11:37:53
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//暴力拼接
int date2Day(char* day, int dayLen) {
    int res = 0;
    if (3 == dayLen) {
        res = day[0] - '0';
    } else {
        res = (day[0] - '0') * 10 + day[1] - '0';
    }
    return res;
}
int date2Mon(char* month) {
    int         res     = 0;
    const char* MONTH[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (int i = 0; i < 12; i++) {
        if (0 == strcmp(month, MONTH[i])) {
            res = i + 1;
            break;
        }
    }
    return res;
}
/**
 * @name: num2str
 * @brief: 数字转字符串
 * @param {*}
 * @retval: none
 */
void num2str(int num, char* str, int pos) {
    if (num < 10) {
        str[pos]     = '0';
        str[pos + 1] = num + '0';
    } else {
        str[pos + 1] = num % 10 + '0';
        str[pos]     = num / 10 + '0';
    }
    return 0;
}
//利用strtok
char* reformatDate(char* date) {
    const char s[2] = " ";
    char*      token;
    token   = strtok(date, s);
    int day = date2Day(token, strlen(token));
    // 继续获取其他的子字符串
    token       = strtok(NULL, s);
    int   month = date2Mon(token);
    char* res   = (char*)malloc(11 * sizeof(char));
    res[4]      = '-';
    res[7]      = '-';
    res[10]     = '\0';
    token       = strtok(NULL, s);
    strncpy(res, token, 4);
    num2str(month, res, 5);
    num2str(day, res, 8);
    // printf("%s\r\n", res);
    return res;
}
//参考题解，格式化字符串
// sscanf   格式化输入
// atoi     ascii转整型
// itoa     整型转字符串
#define MAX_LEN 11
#define MONTH 12

char month[MONTH][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

char* reformatDate(char* date) {
    char  day[5]        = {0};
    char  year[5]       = {0};
    char  month_temp[4] = {0};
    int   imonth;
    char* ans = (char*)malloc(sizeof(char) * MAX_LEN);
    sscanf(date, "%[0-9]%*[a-z] %s %s", day, month_temp, year);    // sscanf可以格式化输入
    for (int i = 0; i < MONTH; i++) {
        if (strcmp(month_temp, &month[i]) == 0) {
            imonth = i + 1;    //相同则将日期返回
        }
    }
    sprintf(ans, "%s-%02d-%02d", year, imonth, atoi(day));
    return ans;
}
