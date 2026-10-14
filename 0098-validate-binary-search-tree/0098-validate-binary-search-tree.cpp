/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNodright;
 * <=  TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    using tn=TreeNode *;
    bool solve(tn root, long long maxi, long long mini){
        if(root==nullptr)return true;
        long long rv=root->val;
       tn l=root->left;
        tn r=root->right;
        if(rv>=maxi || rv<=mini)return false;
       return solve(l,rv,mini) && solve(r,maxi,rv);
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        long long maxi=LLONG_MAX;
        long long mini=LLONG_MIN;
        return solve(root,maxi,mini);
        
    }
};