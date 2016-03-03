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
    p->next = NULL;
    while (q) {
        head = q->next;
        q->next = p;
        p = q;
        q = head;
    }
    return p;
}