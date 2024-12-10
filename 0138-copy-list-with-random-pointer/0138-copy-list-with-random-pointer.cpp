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
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        Node* newhead=new Node(head->val);
        map<Node *,Node *> forrandom;
       
        Node*  nc=newhead;
        Node* c=head;
        forrandom[c]=nc;
        c=c->next;
        while(c!=nullptr){
            nc->next= new Node(c->val);
            nc=nc->next;
            forrandom[c]=nc;
            c=c->next;


        }
        c=head;
        nc=newhead;
        while(c!=nullptr && nc!=nullptr){
         Node* temp=c->random;
         nc->random=forrandom[temp];
         nc=nc->next;
         c=c->next;
        }
     return newhead;    
    }
   
};