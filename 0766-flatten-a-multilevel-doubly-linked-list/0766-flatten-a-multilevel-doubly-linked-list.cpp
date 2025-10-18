/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
   using n=Node*;
   n flattentail(n tail){
    if(tail==nullptr)return tail;
    if(tail->next==nullptr && tail->child==nullptr)return tail;
   // if(tail->next==nullptr)return flatten(tail->child)
    if(tail->child==nullptr)return flattentail(tail->next);
    n nxt=tail->next;
    n child=tail->child;
    tail->next=child;
    tail->child=nullptr;
    child->prev=tail;
    n fc=flattentail(child);
    if(nxt==nullptr)return fc;
    fc->next=nxt;
    nxt->prev=fc;

    return flattentail(nxt);




   }
    Node* flatten(Node* head) {
        if(head==nullptr)return head;
        flattentail(head);
        return head;
        
        
    }
};