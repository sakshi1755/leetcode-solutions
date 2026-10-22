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
    using ln=ListNode*;
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ln fast=head->next;
        
        ln slow=head;
        while(fast!=slow && fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

        }
        if(fast==nullptr|| fast->next==nullptr)return false;
        else return true;
        
    }
};