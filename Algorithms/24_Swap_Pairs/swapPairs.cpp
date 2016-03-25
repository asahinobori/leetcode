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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
            next;
            prev = cur, cur = cur->next, next = cur ? cur->next : nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};

//下面这种写法更简洁，但题目规定了不准这样做
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        while (p && p->next) {
            swap(p->val, p->next->val);
            p = p->next->next;
        }
        return head;
    }
};