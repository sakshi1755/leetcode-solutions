//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node * reverse(Node* head){
        if(head==nullptr)return head;
        
        Node *temp=head->next;
        Node* prev=head;
        if(temp==nullptr)return head;
        Node * next=temp->next;
        
        head->next=nullptr;
        while(temp!=nullptr){
            temp->next=prev;
            prev=temp;
            temp=next;
            if(next!=nullptr)next=next->next;
        }
        return prev;
        
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        if(num1==nullptr)return num2;
         if(num2==nullptr)return num1;
        Node* head1= reverse( num1);
        Node* head2=reverse( num2);
        Node* temp1=head1->next;
        Node* temp2=head2->next;
        int data1,data2;
        Node* head3=new Node((head1->data+head2->data)%10);
        Node* temp3=head3;
        int carry=(head1->data+head2->data)/10;
        while(temp1!=nullptr || temp2!=nullptr){
            if(temp1==nullptr)data1=0;
            else data1=temp1->data;
           if(temp2==nullptr)data2=0;
            else data2=temp2->data;
            int sum=data1+data2+carry;
            temp3->next=new Node(sum%10);
            temp3=temp3->next;
            carry=sum/10;
             if(temp1!=nullptr)temp1=temp1->next;
             if(temp2!=nullptr)temp2=temp2->next;
        }
        if(carry!=0) temp3->next=new Node(carry);
        head3= reverse(head3);
       if(head3->data==0) head3=head3->next;
       return head3;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends