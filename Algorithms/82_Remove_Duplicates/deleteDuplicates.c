/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;
    // 题目已说这单链表已经排序
    // 这里(偷懒)假设是递增排序，实际要简单测试是递增还是递减
    // 取一个val不会与单链表中各节点val重复的值作为mark值
    // 鉴于上面的假设，取mark值为比头节点还要小的值，如head->val - 1
    int mark = head->val - 1;
    // top指向当前判断中(是否存在重复字符)的子字符串的头
    struct ListNode* top = head;
    // cursor一直向前移动
    struct ListNode* cursor = head->next;
    // 是否存在重复字符串
    bool flag = false;
    while (cursor) {
        if (cursor->val == top->val) {
            cursor = cursor->next;
            top->next = cursor;
            flag = true;
            continue;
        }
        if (flag) {
            top->val = mark;
            flag = false;
        }
        top = cursor;
        cursor = cursor->next;
    }
    if (flag) {
        top->val = mark;
        flag = false;
    }
    top = head;
    while (top && top->val == mark) {
        head = top->next;
        top = top->next;
    }
    while (top && top->next) {
        if (top->next->val == mark) {
            top->next = top->next->next;
            continue;
        }
        top = top->next;
    }
    return head;
}