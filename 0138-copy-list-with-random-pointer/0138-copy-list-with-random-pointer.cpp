/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    using n=Node*;
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return nullptr;
        map<n,n>self;
        map<n,n>random;
        n head2=new Node(head->val);
        self[head]=head2;
        random[head]=head->random;
        n curr1=head;
        n curr2=head2;
        while(curr1->next!=nullptr){
            curr1=curr1->next;
            curr2->next=new Node(curr1->val);
            curr2=curr2->next;
            self[curr1]=curr2;
            random[curr1]=curr1->random;


        }
        curr1=head;
        curr2=head2;
        while(curr1!=nullptr){
            curr2->random=self[random[curr1]];
            curr1=curr1->next;
            curr2=curr2->next;
        }



    return head2;
    }
};