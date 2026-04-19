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
        ListNode* head_0 = new ListNode(0, head);
        ListNode* left = head_0;
        ListNode* right = head_0;
        while(n-- >= 0) right = right->next;
        while(right) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return head_0->next;

    }
};
