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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        vector<int>temp;
        queue<tn>q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            tn top=q.front();
            q.pop();
            if(top==nullptr){
                ans.push_back(temp);
                temp={};
             if(!q.empty())   q.push(nullptr);
            }
            else{
            temp.push_back(top->val);
            if(top->left!=nullptr)q.push(top->left);
            if(top->right!=nullptr)q.push(top->right);


            }
            
        }
        return ans;
        
        
    }
};