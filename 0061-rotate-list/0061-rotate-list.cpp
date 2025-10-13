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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==nullptr || head->next==nullptr || k==0)return head;
        ln tail=head->next;
        ln prevtail=head;
        int count=1;
        while(tail->next!=nullptr){
            tail=tail->next;
            prevtail=prevtail->next;
            count++;
        }
        count++;
        
        k=k%count;
       if(k==0)return head;
            
            prevtail->next=nullptr;
            tail->next=head;
            head=tail;
            return rotateRight(head,k-1);
        
        
    }
};