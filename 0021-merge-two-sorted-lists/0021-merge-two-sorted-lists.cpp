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
 ListNode* solve(ListNode* first, ListNode* second){
        ListNode* prev=first;
        ListNode* curr=prev->next;
        ListNode* temp=second;
        while(temp!=nullptr){
        if(curr == nullptr ||temp->val >= prev->val && temp->val <= curr->val ){
            ListNode* temphead= temp->next;
            prev->next=temp;
            temp->next=curr;
            prev=temp;
            temp=temphead;
        }
        else {
            prev=curr;
            curr=curr->next;
        }
        }
        return first;
        

    }
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first -> val <= second -> val ){
       ListNode* ans= solve(first, second);
       return ans;
    }
    else
    {
       ListNode* ans= solve(second, first);
       return ans;
    }
    
    }
};