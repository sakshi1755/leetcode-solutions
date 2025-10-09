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
    ListNode* middleNode(ListNode* head) {
        ListNode* tail=head;
        ListNode* middle=head;
        int i=0;
        while(tail!=nullptr){
            i++;
         if(i>0 && i%2==0){
             middle=middle->next;
         }
         tail=tail->next;
        }
        return middle;
        
    }
};