/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-25 23:15:27
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
/** 算法分析：
 * + 输入：一系列数组、数组大小已知
 * + 输出：最长的“山脉”长度
 * + 实现：1、找到山脉的起始位置p1
 *        2、找到山脉的截止位置p2
 *        3、找到MAX[p2-p1]
 *
 *
 **/
int longestMountain(int* A, int ASize) {
    int  maxLength   = 0;       //最长的山脉长度
    int* startPtr    = NULL;    //山脉起始位置
    int* endPtr      = NULL;    //山脉结束位置
    int  tempLength  = 0;       //当前山脉的长度
    int  lastNum     = 0;       //上一个值
    int  mountainING = 0;       //山脉计算标志位，-1为下行，1为上行，0为未计算
    int  cnt         = 0;
    //开始找山脉
    for (int i = 0; i < ASize; i++) {
        // printf("!!!:A[%d]:%d |",i,*(A+i));
        if (*(A + i) > lastNum) {
            if (mountainING != 1) {
                if (mountainING == -1) {                   //山脉下行
                    endPtr     = A + i - 1;                //标记上一个数为山脉终止
                    tempLength = endPtr - startPtr + 1;    //计算山脉长度
                    if (tempLength > maxLength) {
                        maxLength = tempLength;    //比较是否为当前最长的山脉
                    }
                    // cnt =0;
                    // printf("1maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
                }
                if (i != 0) {
                    startPtr    = A + i - 1;    //更新山脉起始位置
                    mountainING = 1;            //标记当前状态为上行
                    // cnt++;
                } else {
                    startPtr    = A + i;    //更新山脉起始位置
                    mountainING = 0;        //标记当前状态为上行
                }

                // printf("2maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
            }
            // printf("3maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);

        } else if (*(A + i) == lastNum) {
            if (mountainING == -1) {
                endPtr     = A + i - 1;                //标记上一个数为山脉终止
                tempLength = endPtr - startPtr + 1;    //计算山脉长度
                if (tempLength > maxLength) {
                    maxLength = tempLength;    //比较是否为当前最长的山脉
                }
                // printf("4maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
            }
            // cnt = 0;
            mountainING = 0;       //山脉状态重记
            startPtr    = NULL;    //重置山脉起始位置
            // printf("5maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
        } else {
            //山脉下行
            if (mountainING == 1) {
                endPtr = A + i;    //之前上行，从A+i开始下行，暂时将当前位置标记为endPtr
                if (i == (ASize - 1)) {
                    tempLength = endPtr - startPtr + 1;    //计算山脉长度
                    if (tempLength > maxLength) {
                        maxLength = tempLength;    //比较是否为当前最长的山脉
                    }
                    // cnt++;
                    // printf("7maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
                    break;
                }
                mountainING = -1;    //更新标志位为下行状态
                // cnt++;
                // printf("6maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
            } else if (mountainING == -1) {
                //查看i是否为ASize-1。如果是，则需要特殊处理；否则，通过通过下一个值比大小进行其他处理
                if (i == (ASize - 1)) {
                    endPtr     = A + i;                    //标记上一个数为山脉终止
                    tempLength = endPtr - startPtr + 1;    //计算山脉长度
                    if (tempLength > maxLength) {
                        maxLength = tempLength;    //比较是否为当前最长的山脉
                    }
                    // cnt++;
                    // printf("7maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
                    break;
                } else {
                    endPtr = A + i;    //更新当前位置标记为endPtr
                                       // cnt++;
                    // printf("8maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
                }
            } else {
                // cnt = 0;
                endPtr = NULL;
                // printf("9maxL:%d | mF:%d |cnt:%d\r\n",maxLength,mountainING, cnt);
            }
            // printf("maxL:%d | sPtr:%d | ePtr:%d |cnt:%d\r\n",maxLength,startPtr,endPtr, cnt);
        }
        // printf("lastNum:%d\r\n",lastNum);
        lastNum = *(A + i);    //更新lastNum
    }
    return maxLength;
}
