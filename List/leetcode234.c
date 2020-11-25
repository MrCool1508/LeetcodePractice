/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-23 10:32:02
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>
#include <stdio.h>
bool isPalindrome(struct ListNode* head) {
    bool             res     = false;
    int              cnt     = 0;    //记录数组长度
    struct ListNode* nodePtr = head;

    //将链表所有数据取出
    while (nodePtr != NULL) {
        nodePtr = nodePtr->next;
        cnt++;
    }
    if (cnt <= 1) {
        res = true;
        return res;
    }
    int* p  = (int*)calloc(sizeof(int), cnt);
    nodePtr = head;
    while (nodePtr != NULL) {
        *p      = nodePtr->val;
        nodePtr = nodePtr->next;
        *p++;
    }
    *p--;
    // printf("cnt:%d | *p: %d | *(p-cnt+1):%d\r\n", cnt, *p, *(p-cnt+1));

    int loopCnt = cnt / 2;
    for (int i = 0; i < loopCnt; i++) {
        // printf("%d | %d\r\n", *(p-i), *(p+1+i-cnt));
        if (*(p - i) != *(p - cnt + 1 + i)) {
            res = false;
            break;
        } else {
            res = true;
        }
    }
    return res;
}
