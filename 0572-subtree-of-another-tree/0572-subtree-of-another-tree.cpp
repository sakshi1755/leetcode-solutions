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
class Solution {
public:
    using tn=TreeNode*;
    bool isSame(tn root, tn subroot){
        if(root==NULL && subroot==NULL )return true;
        if(root==NULL || subroot==NULL)return false;
        if(root->val!=subroot->val)return false;
        else return isSame(root->left,subroot->left) && isSame(root->right,subroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)return true;
        if(root==NULL || subRoot==NULL)return false;
        
        bool ans=false;
        if(root->val==subRoot->val){
            ans=(isSame(root->left,subRoot->left)&& isSame(root->right,subRoot->right));
            
        }
        if(ans)return ans;        
        ans=(isSubtree(root->left,subRoot)|| isSubtree(root->right,subRoot));
        return ans;
    }
};