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
    using ln=ListNode*;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr && n==1){
                return nullptr;
        }
        int k=n-1;
        ln tail=head;
        ln nthnode=head;
        ln before=head;
        while( tail!=nullptr && k>=0){
            tail=tail->next;
           
           
             k--;
            
        }
        
        
        while(tail!=nullptr){
            if(tail->next!=nullptr)  before=before->next;
            tail=tail->next;
            nthnode=nthnode->next;
         
        }
        if(nthnode==head){
            return head->next;
        }
        before->next=nthnode->next;
        return head;

        
    }
};