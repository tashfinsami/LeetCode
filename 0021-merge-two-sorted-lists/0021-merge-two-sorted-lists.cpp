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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode** temp = &head;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                *temp = list1;
                list1 = list1->next;
            }
            else {
                *temp = list2; 
                list2 = list2->next;
            }
            temp = &(*temp)->next;
        }
        while(list1) {
            *temp = list1; 
            temp = &(*temp)->next;
            list1 = list1->next;
        }
        while(list2) {
            *temp = list2; 
            temp = &(*temp)->next;
            list2 = list2->next;
        }
        if(head) *temp = nullptr;
        return head;
    }
};



