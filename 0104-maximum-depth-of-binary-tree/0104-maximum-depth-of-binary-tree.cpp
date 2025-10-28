/**
 * Definition for a binary tree node.
c
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        return  1+max(maxDepth(root->left),maxDepth(root->right));
    }
};