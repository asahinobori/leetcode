/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return head;
    if (head->next == NULL) return head;
    struct ListNode *p = head;
    struct ListNode *q = head->next;
    struct ListNode *tmp = NULL;
    while (q) {
        tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
    }
    head->next = NULL;
    return p;
}