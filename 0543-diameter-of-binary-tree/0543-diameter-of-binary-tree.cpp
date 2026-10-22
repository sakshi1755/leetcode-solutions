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
    using tn=TreeNode *;
    int solve(tn root, int &ans){
        if(root==nullptr)return 0;
        int lt=solve(root->left,ans);
        int rt=solve(root->right,ans);
        ans=max(ans,lt+rt+1);
        return max(lt+1,rt+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans-1;
        
    }
};