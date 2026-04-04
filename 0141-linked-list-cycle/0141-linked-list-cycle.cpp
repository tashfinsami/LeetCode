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
    bool hasCycle(ListNode* head) {
        if(!head || !head->next) return false;
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head->next;
        while(fast_ptr && fast_ptr->next) {
            if(fast_ptr == slow_ptr) return true;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return false;
    }
};
