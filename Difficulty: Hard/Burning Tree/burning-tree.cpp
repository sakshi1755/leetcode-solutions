//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* findnode(int target,Node*root){
        if(root==nullptr)return NULL;
        if(root->data==target)return root;
        if(findnode(target,root->left))return findnode(target,root->left);
        if(findnode(target,root->right))return findnode(target,root->right);
         return nullptr;
    }
    void mapping(map<Node*,Node*> &nodetoparent, Node*root){
        if(root==nullptr)return ;
        if(root->left) nodetoparent[root->left]=root;
        if(root->right) nodetoparent[root->right]=root;
        mapping(nodetoparent,root->left);
        mapping(nodetoparent,root->right);
    }
    
    int minTime(Node* root, int target) {
        map<Node*,Node*> nodetoparent; //node phir parent
        mapping(nodetoparent,root);
        map<Node*, bool>isvisited;
        Node *tn=findnode(target,root);
        queue<Node*> q;
        q.push(tn);
        isvisited[tn]=true;
        int time=0;
        
        while(!q.empty()){
             int size = q.size(); // Number of nodes in the current level
              bool flag = false;
              for (int i = 0; i < size; i++){
                 Node* temp= q.front();
                   q.pop();
           
           
          
            if(temp->left && !isvisited[temp->left]){
                q.push(temp->left);
                isvisited[temp->left]=true;
                flag=true;
            }
            if(temp->right && !isvisited[temp->right]){
                q.push(temp->right);
                isvisited[temp->right]=true;
                flag=true;
            }
            if(nodetoparent[temp] && !isvisited[nodetoparent[temp]]){
                q.push(nodetoparent[temp]);
                isvisited[nodetoparent[temp]]=true;
                flag=true;
            }
              }
           if(flag)time++;
        
        }
        
       return time; 
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends