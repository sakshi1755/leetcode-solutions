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
    void solve(tn root, long long &sum, long long currnum){
        if(root==nullptr)return;
        currnum=currnum*10+root->val;
        if(root->left==nullptr && root->right==nullptr){
            sum+=currnum;
            return;
        }
        solve(root->left,sum,currnum);
        solve(root->right,sum, currnum);
        


    }
    int sumNumbers(TreeNode* root) {
        long long sum=0;
        long long currnum=0;
         solve(root,sum,currnum);
        return sum;
    }
};