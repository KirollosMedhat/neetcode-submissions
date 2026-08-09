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
        ListNode dummy;
        ListNode* it = &dummy;
        ListNode* current1=list1;
        ListNode* current2=list2;
        

        while(current1 && current2){
            if(current1->val <= current2->val){
                it->next = current1;
                it = it->next;
                current1 = current1->next;
            }else{
                it->next = current2;
                it = it->next;
                current2 = current2->next;
            }
        }

        while(current1){
            it->next = current1;
            it = it->next;
            current1 = current1->next;
        }

        while(current2){
            it->next = current2;
            it = it->next;
            current2 = current2->next;
        }

        
        ListNode* head = dummy.next;

        return head;
        
    }
};
