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
using ln=ListNode*;
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr)return head;
        if(head->next==nullptr)return head;
        if(head->next->next==nullptr)return head;
        ln evenhead=head->next;
        ln oddhead=head;
        ln odd=oddhead;
        ln even=evenhead;
        while(even!=nullptr && even->next!=nullptr){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;


        }
        odd->next=evenhead;
        return oddhead;


        
        return head;
    }
};