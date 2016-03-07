/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 递归版
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode *p = head->next;
    if (head->val == p->val) {
        while (p && head->val == p->val) {
            p = p->next;
        }
        return deleteDuplicates(p);
    } else {
        head->next = deleteDuplicates(head->next);
        return head;
    }
}

// 迭代版
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return head;
    struct ListNode dummy;
    dummy.val = INT_MIN;
    dummy.next = head;
    struct ListNode *prev = &dummy, *cur = head;
    while (cur != NULL) {
        bool duplicated = false;
        while (cur->next != NULL && cur->val == cur->next->val) {
            duplicated = true;
            cur = cur->next;
        }
        if (duplicated) {
            cur = cur->next;
            continue;
        }
        prev->next = cur;
        prev = prev->next;
        cur = cur->next;
    }
    prev->next = cur;
    return dummy.next;
}