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
   void solve(tn root, int level,int row,map<int,vector<tn>>&mp,map<tn,int>&rrow){
        if(root==nullptr)return;
        mp[level].push_back(root);
        rrow[root]=row;
        solve(root->left,level-1,row+1,mp,rrow);
        solve(root->right,level+1,row+1,mp,rrow);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<tn>>mp;
      // mp[0].push(root);
      map<tn,int>rrow;
        solve(root,0,0,mp,rrow);
        vector<vector<int>>ans;
        for(auto it : mp){
            sort(it.second.begin(),it.second.end(),[&](tn a,tn b){
                if(rrow[a]==rrow[b])return a->val<b->val;
              return  rrow[a]<rrow[b];
            });
            vector<int>temp;
            for(int i=0;i<it.second.size();i++){
                temp.push_back(it.second[i]->val);
            }
            ans.push_back(temp);

        }
        return ans;
        
    }
};