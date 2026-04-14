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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* ptr = head;
        while(ptr) {
            stk.push(ptr);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr != stk.top() && ptr->next != stk.top()) {
            ListNode* temp = ptr->next;
            ptr->next = stk.top();
            stk.pop();
            ptr->next->next = temp;
            ptr = temp;
        }
        //if(ptr == stk.top()) ptr->next = nullptr;
        //else if(ptr->next == stk.top())ptr->next->next = nullptr;
        stk.top()->next = nullptr;
    }
};
