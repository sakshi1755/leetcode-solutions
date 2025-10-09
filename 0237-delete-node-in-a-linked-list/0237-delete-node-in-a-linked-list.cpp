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
    void deleteNode(ListNode* node) {
        ListNode* next= node->next;
        int val=next->val;
        ListNode* nextnode=next->next;
        node->val=val;
        node->next=nextnode;
         



    }
};