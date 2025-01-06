//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node* solve(vector<int> &inorder, vector<int> &postorder, int &index, int startin,int endin, map<int,int>&m){
        if(index<0 || startin>endin) return nullptr;
        int e=postorder[index];
        int pos=m[e];
        Node* root=new Node(e);
        index--;
        root->right=solve(inorder,postorder,index,pos+1,endin,m);
        root->left=solve(inorder, postorder,index,startin,pos-1,m);
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        map<int,int> m;
         int n=inorder.size();
        for(int i=0;i<n;i++){
            int e=inorder[i];
            m[e]=i;
        }
        int index=n-1;
        return solve(inorder,postorder,index,0,n-1,m);
        
        
        
        
        
        
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends