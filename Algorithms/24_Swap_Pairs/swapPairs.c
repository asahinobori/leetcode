/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || head->next == NULL) return head;
    struct ListNode* p = head;
    struct ListNode* q = head->next;
    struct ListNode* newHead = q;
    do {
        struct ListNode* tmp = q->next;
        q->next = p;
        if (tmp && tmp->next) {
            p->next = tmp->next;
            p = tmp;
            q = tmp->next;
        } else {
            p->next = tmp;
            p = tmp;
            q = NULL;
        }
    } while (p && q);
    return newHead;
}