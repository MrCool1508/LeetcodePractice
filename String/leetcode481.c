/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-06 10:12:38
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int generateNum(int n) {
    int* res        = (int*)calloc(n, sizeof(int));    //创建n个数字大小暂存数组
    res[0]          = 1;                               //第一个数为1
    int  oneFlag    = 0;                               //数字标志位：0为1,1为2
    int  cnt        = 0;                               //连续计数器
    int  pos        = 1;                               //当前位置，从第二个数开始
    int  oneCnt     = 0;                               // 1的数量计数器
    int* p_fast     = res;                             //快指针
    int* p_slow     = res;                             //慢指针
    int  contnCnt   = 0;                               //连续的次数
    int  currentNum = 0;                               //当前的数字1or2

    while (pos < n) {
        contnCnt   = *p_slow;         //连续的次数为慢指针所指向的值
        currentNum = oneFlag + 1;     //更新当前数字
        while (cnt < contnCnt) {      //当连续计数器<连续的次数时
            *p_fast++;                //移动快指针
            *p_fast = currentNum;     //将当前值赋值给快指针所指向的位置
            if (currentNum == 1) {    //记录是否为1
                oneCnt++;
            }
            pos++;             //记录当前位置
            if (pos >= n) {    //如果当前位置已经为n，则结束循环，避免溢出
                break;
            }
            cnt++;    //更新连续计数器
        }
        oneFlag = !oneFlag;    //更新当前数字
        cnt     = 0;           //重置连续计数器
        *p_slow++;             //更新慢指针的位置，为下一次连续次数做准备
    }
    free(res);    //释放res的内存
    return oneCnt;
}

int magicalString(int n) {
    int res = 0;    //计1的数量
    if (n < 1) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        res = generateNum(n);
        return res;
    }
}
