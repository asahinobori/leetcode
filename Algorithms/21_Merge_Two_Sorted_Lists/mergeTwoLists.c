/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head = {-1, NULL};
    struct ListNode* cur = &head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
    }
    if (!l1) cur->next = l2;
    if (!l2) cur->next = l1;
    return head.next;
}