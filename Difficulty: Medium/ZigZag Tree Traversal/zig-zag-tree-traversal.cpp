//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
/*Structure of the node of the binary tree is as
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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector <int> v;
    	queue<Node*> q;
    	int count=1;
    	q.push(root);
    	v.push_back(root->data);
    	q.push(nullptr);
    	while(!q.empty()){
    	    Node * temp=q.front();
    	    q.pop();
    	    if(temp==nullptr){
    	        
    	        count++;
    	       
    	        if(!q.empty()){
    	            int size=q.size();
    	            
    	            vector<int> v2(size);
    	            
    	            if(count%2==0 ){
    	                for(int i=size-1;i>=0;i--){
    	                    v2[i]=q.front()->data;
    	                    q.push(q.front());
    	                    q.pop();
    	                }
    	            }
    	            else{
    	                  for(int i=0;i<size;i++){
    	                    v2[i]=q.front()->data;
    	                    q.push(q.front());
    	                    q.pop();
    	                }
    	                
    	            }
    	            q.push(nullptr);
    	               for (int i = 0; i < size; i++) {
                            v.push_back(v2[i]); // Add reversed level to result.
                        }
    	        
    	        
    	        }
    	        
    	    }
    	    else{
    	      if(temp->left!=nullptr)  q.push(temp->left);
    	       if(temp->right!=nullptr)  q.push(temp->right);
    	       
    	       // if(count%2==1){
    	             
    	       //if(temp->right!=nullptr)  v.push_back(temp->right->data);
    	        //if(temp->left!=nullptr)  v.push_back(temp->left->data);
    	        //}
    	        //if(count%2==0){
    	             
    	     
    	        //if(temp->left!=nullptr)  v.push_back(temp->left->data);
    	          //vif(temp->right!=nullptr)  v.push_back(temp->right->data);
    	        //}
    	        
    	    }
    	}
    	return v;// Code here
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends