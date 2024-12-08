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
   ListNode* reverse(ListNode* head, int k){
      ListNode* curr=head;
      ListNode* prev=nullptr;
      ListNode* next;
    for(int j=0;j<k && curr != nullptr;j++){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

        
    }

head->next=curr;
return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
    

    ListNode* curr=head;
    ListNode* newhead=nullptr;
    ListNode *prevtail=nullptr;
    while(curr!=nullptr){
         int count=0;
          ListNode* temphead=curr;
        for(int i=1; i<=k;i++){

            if (curr != nullptr) {
                count++;
                curr = curr->next;
            } else {
                break; // End of the list reached, stop counting
            }
        }
        if(count==k){
            ListNode* reversedhead= reverse(temphead,k) ;
            if (newhead == nullptr) {
              newhead = reversedhead;
            }
            if (prevtail != nullptr) {
              prevtail->next = reversedhead;
            }
            prevtail = temphead;
        } else {
            if (prevtail != nullptr) {
                prevtail->next = temphead; // Connect the last group's tail to the 
            }
        }
    }
   return newhead; // Write your code here.
}  
    
};