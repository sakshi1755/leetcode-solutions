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
    struct compare{
        bool operator()(ListNode * a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int k=lists.size();
      priority_queue<ListNode*, vector<ListNode*>, compare> q;
      for(int i=0 ; i<k ;i++){
             if (lists[i] != nullptr) q.push(lists[i]);
        }
      ListNode* head=NULL;
      ListNode* tail=NULL;
      while(!q.empty()){
        ListNode* top= q.top();
          q.pop();
        if(head==nullptr){
            head=top;
            tail=top;
        }
        else{
            tail->next=top;
            tail=tail->next;
        }
        if(top->next!=nullptr){
            q.push(top->next);
        }
      

      } 
      return head;

    }
};