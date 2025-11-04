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
    long long solve(tn root,long long & ans){
        if(root==nullptr)return LLONG_MIN;
long long  l = max(0LL, solve(root->left, ans));
long long r = max(0LL, solve(root->right, ans));

        long long val=root->val;
        long long tempans=val;
      if(l!=LLONG_MIN)  tempans=max(tempans,l+val);
       if(r!=LLONG_MIN) tempans=max(tempans,r+val);
      // if(l!=LLONG_MIN && r!=LLONG_MIN) tempans=max(tempans,l+r+val);
        ans=max(ans,val+l+r);
        return tempans;
    }
    int maxPathSum(TreeNode* root) {
        long long  ans=LLONG_MIN;
        solve(root,ans);
        return ans;

        
    }
};