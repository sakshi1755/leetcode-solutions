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
   ln findmiddle(ln head){
        if(head==nullptr || head->next==nullptr)return head; 
        ln fast=head;
        ln slow=head;
        // slow=slow->next;
        // fast=fast->next->next;
        while(fast->next && fast->next->next){
          slow=slow->next;
          fast=fast->next->next;

        }
        return slow;

    }
    ln mergedTwoSortedlist(ln left, ln right){
        ln ls=left;
        ln rs=right;
        ln dummynode=new ListNode(-1);
        ln temp=dummynode;
        while(left!=nullptr || right!=nullptr){
            if(left==nullptr){
                temp->next=right;
                right=right->next;
            }
            else if(right==nullptr){
                temp->next=left;
                left=left->next;
            }
            else if(left->val<right->val){
                temp->next=left;
                left=left->next;
                
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        return dummynode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
       ln middle= findmiddle(head);
       ln right=middle->next;
       middle->next=nullptr;
       ln left=head;
       left=sortList(left);
       right=sortList(right);
       return mergedTwoSortedlist(left,right);
        
    }
};