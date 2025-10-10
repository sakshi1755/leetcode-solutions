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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr)return head;
        if(head->next==nullptr)return nullptr;
        ln tail=head;
        ln middle=head;
        ln before=head;
        int i=0;
        tail=tail->next;

        while(tail!=nullptr){
            if(i%2==0 )middle=middle->next;
            if(i%2==0 && i>0) before=before->next;
            tail=tail->next;
            i++;

        }
        before->next=middle->next;
        return head;


        
    }
};