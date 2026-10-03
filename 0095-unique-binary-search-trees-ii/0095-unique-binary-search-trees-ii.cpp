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
    vector<tn> solve(int s,int e, vector<vector<vector<tn>>>&dp){
        if(s>e) return {nullptr};
        if((dp[s][e].size()>0))return dp[s][e];
        if(s==e){
            TreeNode* head= new TreeNode(e+1);
            dp[s][e]={head};
            return dp[s][e];
        }
          vector<tn>ans;
        for(int i=s;i<=e;i++){
            vector<tn>lefti=solve(s,i-1,dp);
            vector<tn>righti=solve(i+1,e,dp);
          
            
            for(int l=0;l<lefti.size();l++){

                for(int r=0;r<righti.size();r++){
                    tn head= new TreeNode(i+1);
                    head->left=lefti[l];
                    head->right=righti[r];
                    ans.push_back(head);
                    


                }
            }

        }
        return dp[s][e]=ans;
        



    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<tn>>>dp(n+1,vector<vector<tn>>(n+1));
        return solve(0,n-1,dp);

        
    }
};