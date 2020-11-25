/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-18 19:42:42
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int              tempVal  = 0;
    struct ListNode* tempNode = head;
    int              cnt      = 1;
    struct ListNode* res      = head;
    //计算链路总节点个数
    while ((tempNode->next) != NULL) {
        tempNode = tempNode->next;
        cnt++;
    }
    //删除指定节点
    int              i       = 0;
    int              listCnt = cnt - n;    //标记需要删除节点的位置，从0开始
    struct ListNode* resTemp = res;        //记录初始节点的位置
    tempNode                 = head;

    if (listCnt == 0)    //意味着删除第一个节点
    {
        resTemp = res->next;
        free(res);
        return resTemp;
    } else {
        while (listCnt - 1) {
            res->next = tempNode->next;
            res       = res->next;
            listCnt--;
            // printf("%d | %d | %d\r\n",listCnt, tempNode->val, res->val);
        }
        tempNode  = tempNode->next;
        res->next = tempNode->next;
        // printf("%d | %d | %d\r\n",listCnt, tempNode->val, res->val);
        free(tempNode);
    }
    return resTemp;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p, *q, *dev;
    dev       = (struct ListNode*)malloc(sizeof(struct ListNode));
    dev->val  = 0;
    dev->next = head;    //为了对付特殊情况，所以创建一个新的节点，该节点位于head之前
    p         = dev;
    q         = dev;
    int cnt   = 0;
    while (p) {    //双指针，等p->next执行n+2边的时候，q->next开始执行
        cnt++;
        p = p->next;
        if (cnt > n + 1) {
            q = q->next;
            printf("%d | %d\r\n", (p->val), (q->val));
        }
    }
    q->next = q->next->next;    //删除倒数第n个节点
    return dev->next;           //只能这样写，否则写“return head”的话有几组测试样例不能通过
}
