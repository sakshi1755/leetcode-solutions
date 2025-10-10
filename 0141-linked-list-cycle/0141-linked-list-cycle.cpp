/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    using ln=ListNode *;
    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
        ln slow=head;
        ln fast;
       if(head->next!=nullptr) fast=head->next;
       else fast=nullptr;
        while(fast!=nullptr){
            if(slow==fast){
                return true;
            }
            slow=slow->next;
          if(fast->next!=nullptr)  fast=fast->next->next;
          else fast=nullptr;
            
        }
        return false;
        
    }
};