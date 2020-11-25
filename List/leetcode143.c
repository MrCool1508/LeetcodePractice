/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-20 10:15:46
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
void reorderList(struct ListNode* head) {
    struct ListNode* res = head;
    int              cnt = 0;
    while (head != NULL) {
        head = head->next;
        cnt++;
    }
    // printf("%d\r\n", cnt);
    head = res;
    if (cnt > 2) {
        //将链表的指针全部存储到数组中
        struct ListNode* resTemp[cnt];    // = (struct ListNode**)calloc(cnt, sizeof(struct ListNode*));
        head       = res;
        resTemp[0] = head;
        // printf("rTP0:%d\r\n", resTemp[0]->val);
        for (int i = 1; i < cnt; i++) {
            *(resTemp + i) = head->next;
            // printf("val:%d\r\n",head->val);
            head = head->next;
        }
        //断链重排
        head                     = res;
        struct ListNode* temp_1  = (struct ListNode*)malloc(sizeof(struct ListNode*));
        int              cntTemp = cnt / 2;
        if (cnt % 2 == 0) {
            cntTemp--;
        }

        for (int i = 0; i < cntTemp; i++) {
            temp_1                           = head->next;
            head->next                       = *(resTemp + cnt - 1 - i);
            (*(resTemp + cnt - 2 - i))->next = NULL;
            (*(resTemp + cnt - 1 - i))->next = temp_1;
            // printf("i:%d | val:%d | tp1：%d\r\n", i, head->val, temp_1->val);
            head = head->next;
            head = head->next;
        }
        head = res;
    }
}
