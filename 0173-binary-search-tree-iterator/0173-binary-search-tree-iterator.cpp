/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    using t=TreeNode*;
public:
   stack<t>s;
   void pushleft(t n){
      while(n!=nullptr){
        s.push(n);
        n=n->left;

      }
    }
    BSTIterator(TreeNode* root) {
        pushleft(root);
        
        
    }
    
    int next() {
        t ans=s.top();
        s.pop();
        if(ans->right!=nullptr){
            pushleft(ans->right);
        }
        return ans->val;

        
    }
    
    bool hasNext() {
        if(s.size()==0)return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */