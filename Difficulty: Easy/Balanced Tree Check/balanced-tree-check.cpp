//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

// Function to build a tree from a string representation
Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N')
        return nullptr;

    vector<string> nodeValues;
    istringstream iss(str);
    for (string s; iss >> s;)
        nodeValues.push_back(s);

    Node* root = createNode(stoi(nodeValues[0]));
    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    size_t i = 1;
    while (!nodeQueue.empty() && i < nodeValues.size()) {
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        string leftValue = nodeValues[i++];
        if (leftValue != "N") {
            currentNode->left = createNode(stoi(leftValue));
            nodeQueue.push(currentNode->left);
        }

        if (i >= nodeValues.size())
            break;

        string rightValue = nodeValues[i++];
        if (rightValue != "N") {
            currentNode->right = createNode(stoi(rightValue));
            nodeQueue.push(currentNode->right);
        }
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to check whether a binary tree is balanced or not.
    int maxheight(struct Node* node,int count){
       if(node==NULL)return count;
       count++;
       int maxi=max(maxheight(node->left,count), maxheight(node->right,count));
       return maxi;
    }
    bool isBalanced(Node* root) {
        int count1=0;
        int count2=0;
        int m1=maxheight(root->left,count1);
        int m2=maxheight(root->right,count2);
        if(m1==m2)return true;
        if(m1>m2){
            if(m1-m2>1)return false;
            else return true;
        }
        if(m2>m1){
            if(m2-m1>1)return false;
            else return true;
        }
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (testCases--) {
        string treeInput;
        getline(cin, treeInput);

        Node* root = buildTree(treeInput);
        Solution solution;
        bool result = solution.isBalanced(root);

        // Output "true" or "false"
        cout << (result ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends