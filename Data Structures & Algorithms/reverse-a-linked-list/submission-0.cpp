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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* before, *current, *after;

        before = nullptr;
        current = head; 

        //after = head->next;

        while(current != nullptr){
            ListNode* temp = current;
            current = current->next;
            temp->next = before;
            before = temp;
        }


        return before;
    }
};
