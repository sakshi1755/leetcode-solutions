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
    using ln=  ListNode* ;
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr  ||  head->next==nullptr)return head;
        ln prev=head;
        ln curr=head->next;
        ln next=curr->next;
        while(curr!=nullptr){
            if(prev->val==curr->val){
                prev->next=next;
                curr=next;
                if(curr!=nullptr)next=curr->next;
            }
            else{
                prev=curr;
                curr=next;
                if(curr!=nullptr)next=curr->next;
            }

        }
        return head;

        
        
    }
};