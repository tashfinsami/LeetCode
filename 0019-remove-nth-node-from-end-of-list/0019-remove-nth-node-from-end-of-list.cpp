/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        n = rem(head, n);
        return (n == 0) ? head->next : head;
    }
private:
    int rem(ListNode* cur, int n) {
        if(!cur) return n;
        n = rem(cur->next, n);
        n--;
        if(n == - 1) cur->next = cur->next->next;
        return n;
    }
};
