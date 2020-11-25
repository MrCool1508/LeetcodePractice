/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-13 14:07:54
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *res, *p, *temp, *q, *resTemp;
    res       = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->next = head;
    res->val  = 0;
    resTemp   = res;

    if (head == NULL) {
        return NULL;    //输入空返回空
    } else if (head->next == NULL) {
        return head;    //输入单节点，返回单节点
    } else {
        p = res->next;
        q = p->next;    //输入多节点
    }

    while (q->next != NULL) {
        temp          = q->next;
        q->next       = p;
        resTemp->next = q;
        p->next       = temp;
        resTemp       = p;
        p             = p->next;
        if (p->next != NULL) {
            q = p->next;    //偶数个节点，结束while后需要多进行一次
        } else {
            return res->next;    //奇数个节点，最后一个节点不动，直接返回
        }
    }
    temp          = q->next;
    q->next       = p;
    resTemp->next = q;
    p->next       = temp;
    resTemp       = p;

    return res->next;
}

int main(int argc, char const* argv[]) {
    return 0;
}
