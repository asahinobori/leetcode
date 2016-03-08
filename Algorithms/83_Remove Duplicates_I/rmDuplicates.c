/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return head;
    struct ListNode *cur = head;
    while (cur->next) {
        if (cur->val == cur->next->val) {
            struct ListNode *temp = cur->next;
            cur->next = temp->next;
            cur = temp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}