/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        p->next = nullptr;
        while (q) {
            head = q->next;
            q->next = p;
            p = q;
            q = head;
        }
        return p;
    }
};