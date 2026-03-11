/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 */

// @lc code=start
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
    int findsum(tn root,map<tn,int>&mp){
        if(root==NULL)return 0;
        int ls=findsum(root->left,mp);
        int rs=findsum(root->right,mp);
        mp[root]=ls+rs+root->val;
        return mp[root];
    }
    int maxProduct(TreeNode* root) {
        map<tn,int>mp;
       int ts = findsum(root,mp);
       long long ans=0;
         for(auto it:mp){
              long long val=it.second;
              ans=max(ans,(val*(ts-val)));
         }
         ans=ans%1000000007;
            return ans;
    }
};
// @lc code=end

