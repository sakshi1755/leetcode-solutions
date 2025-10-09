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
    using ln =  ListNode* ;
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        ln tail= head;
        ln prev=head;
        ln curr=head->next;
        ln net;
       if(head->next!=nullptr)  net=head->next->next;
        head->next=nullptr;
        while(curr!=nullptr){
            curr->next=prev;
            prev=curr;
            curr=net;
          if(net!=nullptr)  net=net->next;
            
        }
        return prev;

        
    }
};