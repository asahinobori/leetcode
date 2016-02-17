/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.val = -1;
    dummy.next = NULL;

    for (struct ListNode* p = &dummy; l1 != NULL || l2 != NULL; p = p->next) {
        int val1 = l1 == NULL ? INT_MAX : l1->val;
        int val2 = l2 == NULL ? INT_MAX : l2->val;
        if (val1 <= val2) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
    }
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *fast, *slow;
    fast = head;
    slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow;
    slow = slow->next;
    fast->next = NULL;

    struct ListNode* l1 = sortList(head);
    struct ListNode* l2 = sortList(slow);
    return mergeTwoLists(l1, l2);
}