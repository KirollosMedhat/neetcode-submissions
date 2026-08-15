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
        ListNode* current = head;
        int length = 0; 

        while(current){
            length++;
            current = current -> next;
        }

        if(length == 1 && n == 1){
            return (ListNode*)nullptr;
        }else if(n == length){
            return head -> next;
        }

        current = head -> next;
        ListNode* prev = head;
        for(int i = 0; i < (length - n - 1); i++){
            current = current -> next;
            prev = prev -> next;
        }
        cout<<current->val<<endl;
        cout<<prev->val<<endl;

        prev -> next = current -> next; //de sa7 el mafrood

        current -> next = nullptr;

        return head;

    }
};
