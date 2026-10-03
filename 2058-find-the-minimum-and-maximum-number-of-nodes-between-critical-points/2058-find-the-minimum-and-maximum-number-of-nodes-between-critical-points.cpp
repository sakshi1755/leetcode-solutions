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
    using ln= ListNode* ;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==nullptr)return {-1,-1};
        int i=1;
        ln curr=head->next;
        ln prev=head;
        ln next=head->next->next;
        vector<int>cp;

        while(curr->next!=nullptr){
            int cv=curr->val;
            int pv=prev->val;
            int nv=next->val;
            if(cv>pv && cv>nv)cp.push_back(i);
            if(cv<pv && cv<nv)cp.push_back(i);
            i++;
            curr=curr->next;
            prev=prev->next;
            next=next->next;



        }

        int n=cp.size();

        if(n<2)return {-1,-1};
        int maxi=INT_MIN;
        int mini=INT_MAX;
        maxi=cp[n-1]-cp[0];
        for(int i=0;i<n-1;i++){
            mini=min(mini,cp[i+1]-cp[i]);
        }
        return {mini,maxi};

        
    }
};