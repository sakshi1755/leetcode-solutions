//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
   Node * solve(vector<int> &inorder, vector<int> &preorder, int &index, int startin, int endin, int n, map<int, int>&m){
         if(index>=n || startin>endin )
               return nullptr;
         int element=preorder[index];
         int pos=m.at(element);
         Node* root=new Node(element);
         index++;
         root->left=solve(inorder,preorder,index,startin,pos-1,n,m);
         root->right=solve(inorder,preorder,index,pos+1,endin,n,m);
         return root;
         
         
   }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        map<int,int>m;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            int e=inorder[i];
            m[e]=i;
        }
        int index=0;
        return solve(inorder,preorder,index,0,n-1,n,m);
        
        
        // Code here
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends