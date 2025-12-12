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
    using ln= ListNode*;
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr)return head;
        ln curr=head->next;
        ln prev=head;
        while(curr!=nullptr){
          ln  next=curr->next;
            if(curr->val>=prev->val){
                prev=curr;
                curr=next;
                
            }
            else{
                prev->next=next;
                ln tempcurr=head;
                if(head->val>=curr->val){
                    curr->next=head;
                    head=curr;
                    curr=next;
                    
                }
                else{
                ln tempprev=head;
                while(tempcurr!=nullptr && tempcurr->val<=curr->val){
                     tempprev=tempcurr;
                    tempcurr=tempcurr->next;
                   

                }
                curr->next=tempcurr;
                tempprev->next=curr;
                curr=next;



                }
            }
            
        }
        return head;
        
        
    }
};