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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ln fh=head;
        ln sh=head->next;
        int a=fh->val;
        int b=sh->val;
        fh->val=b;
        sh->val=a;
        head=fh;
        fh=fh->next->next;
       if(fh!=nullptr) sh=sh->next->next;
       else return head;
        while(sh!=nullptr && fh!=nullptr){
            int a=fh->val;
        int b=sh->val;
        fh->val=b;
        sh->val=a;
         fh=fh->next->next;
         if(fh!=nullptr) sh=sh->next->next;
       else return head;
            
        }
        return head;
    }
};