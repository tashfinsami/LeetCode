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
        while(head) {
            if(!head->next) break;
            else if(head->next->val == INT_MAX) return true;
            else {
                ListNode* temp = head->next;
                head = head->next;
                if(temp) temp->val = INT_MAX;
            }
        }
        return false;
    }
};
