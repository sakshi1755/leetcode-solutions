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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int data1,data2;
        ListNode*  curr1=l1;
        ListNode*  curr2=l2;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        
    
        while(curr1!=nullptr || curr2!=nullptr){
            if(curr1==nullptr)data1=0;
             else data1=curr1->val;
            if(curr2==nullptr)data2=0;
            else data2=curr2->val;
            temp->next=new ListNode( (data1+data2+carry)%10);
            carry= (data1+data2+carry)/10;
            
            temp=temp->next;
            
          if(curr1!=nullptr)  curr1=curr1->next;
            if(curr2!=nullptr)  curr2=curr2->next;
            


                
            
        }
         if (carry > 0) {
           
            temp->next = new ListNode(carry);
        }
       
        return dummy->next;
    }
};