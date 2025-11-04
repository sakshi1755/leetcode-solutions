/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    using tn=TreeNode*;
    pair<bool,bool>solve(tn root,tn p,tn q, tn &ans){
        if(root==nullptr)return {false,false};

        if(root==p){
         bool s=solve(root->left,p,q,ans).second||solve(root->right,p,q,ans).second;
         bool f=true;
        if(f && s && ans==nullptr)ans=p;
        return {true,s};
        }
        if(root==q){
        bool f=solve(root->left,p,q,ans).first||solve(root->right,p,q,ans).first;
        bool s=true;
        if(f && s && ans==nullptr)ans=q;
        return {f,s};
        }
        pair<bool,bool>l=solve(root->left,p,q,ans);
        pair<bool,bool>r=solve(root->right,p,q,ans);
        bool f=l.first||r.first;
        bool s=l.second||r.second;
          if(f && s && ans==nullptr)ans=root;
        return {f,s};



        


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        tn ans=nullptr;
        solve(root,p,q,ans);
        return ans;

        
    }
};