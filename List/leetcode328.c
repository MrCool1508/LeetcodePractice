/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-13 12:09:45
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
// 创建一个奇数链表，一个偶数链表，将奇数链表的末尾指向偶数链表的头

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode* evenHead = head->next;    // n2
    struct ListNode* odd      = head;          // n1
    struct ListNode* even     = evenHead;      // n2
    while (even != NULL && even->next != NULL) {
        odd->next  = even->next;    // n1->n3
        odd        = odd->next;     // odd为n3
        even->next = odd->next;     // n2->n4
        even       = even->next;    // even为n4
    }
    odd->next = evenHead;    //奇数链表的结尾指向偶数链表
    return head;
}
