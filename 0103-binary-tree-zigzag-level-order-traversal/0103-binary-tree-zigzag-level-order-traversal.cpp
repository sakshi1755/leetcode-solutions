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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        queue<tn>q;
        q.push(root);
        q.push(nullptr);
        vector<int>temp;
        while(!q.empty()){
            tn t=q.front();
            q.pop();
            if(t==nullptr){
                if(!q.empty()){
                    q.push(nullptr);
                }
                if(!temp.empty()){
                    ans.push_back(temp);
                    vector<int>temp2;
                    temp=temp2;
                }
            }
            else{ temp.push_back(t->val);
               if(t->left!=nullptr) q.push(t->left);
               if(t->right!=nullptr) q.push(t->right);
            }

        }
        int n=ans.size();
        for(int i=1;i<n;i+=2){
            reverse(ans[i].begin(),ans[i].end());

        }
        return ans;
        
    }
};