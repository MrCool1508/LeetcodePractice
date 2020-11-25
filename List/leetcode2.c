/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-26 10:50:06
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * 算法分析：
 *  + 先将ListNode1和2分别合成数字
 *  + 二者相加得到和
 *  + 拆解为各位数
 *  + 缺点：有可能受int大小的限制
 **/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int sumListNode(struct ListNode* l) {
    int res = 0;
    int cnt = 1;
    while (l != NULL) {
        res += cnt * l->val;
        cnt *= 10;
        l = l->next;
    }
    return res;
}
struct ListNode* divideListNode(int num) {
    struct ListNode *res = NULL, *p = NULL;
    p   = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    res = p;
    while (num > 0) {
        p->val = num % 10;
        num /= 10;
        if (num == 0) {
            p->next = NULL;
        } else {
            p->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        }
        p = p->next;
    }
    return res;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int              num_1 = sumListNode(l1);
    int              num_2 = sumListNode(l2);
    int              sum   = 0;
    struct ListNode* res;

    sum = num_1 + num_2;
    res = divideListNode(sum);
    return res;
}
/**
 * 法二：同时处理两个节点的数
 *
 **/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *res, *temp;

    int tempNum = 0;    //大于10
    temp        = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    res         = temp;

    while ((l1 != NULL) || (l2 != NULL)) {
        if (l1 != NULL) {
            tempNum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            tempNum += l2->val;
            l2 = l2->next;
        }
        temp->val = tempNum % 10;    //取末位
        tempNum /= 10;               //取十位
        if ((l1 != NULL) || (l2 != NULL)) {
            temp->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
            temp       = temp->next;
            continue;
        } else {
            if (tempNum != 0) {
                temp->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
                temp       = temp->next;
                temp->val  = tempNum;
                temp->next = NULL;
            } else {
                temp->next = NULL;
            }
        }
    }
    return res;
}
