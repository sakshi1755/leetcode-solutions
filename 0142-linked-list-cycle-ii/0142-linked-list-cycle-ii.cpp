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
   using ln= ListNode *;
   ln findhead(ln head,ln slow,ln fast){
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;

    }
    return slow;
   }
    ListNode *detectCycle(ListNode *head) {
            if(head==nullptr)return nullptr;
        ln slow=head;
        ln fast;
      fast=head;
      
     while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
        return findhead(head, slow, fast);
    }
}
 return nullptr;
        }
        
        
    
};