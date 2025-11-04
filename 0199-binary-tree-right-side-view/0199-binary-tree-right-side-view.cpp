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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        queue<tn>q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>>lt;
        vector<int>temp;
        while(!q.empty()){
            tn t=q.front();
            q.pop();
            if(t==nullptr){
                if(!q.empty())q.push(nullptr);
                if(!temp.empty()){
                    lt.push_back(temp);
                    vector<int>temp2;
                    temp=temp2;
                }
            }
            else{
                temp.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            
        }
        int n=lt.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int s=lt[i].size();
            ans[i]=lt[i][s-1];
        }
        return ans;
        
    }
};