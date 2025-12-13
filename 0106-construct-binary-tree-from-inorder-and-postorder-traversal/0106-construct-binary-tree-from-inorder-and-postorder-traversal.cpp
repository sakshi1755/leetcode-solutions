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
TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int ins, int ine, int pos, int poe,
                    map<int,int>& inmap,map<int,int>&postmap) {

        if (ins > ine || pos > poe) return nullptr;

        TreeNode* root = new TreeNode(postorder[poe]);

        int ri = inmap[root->val];
        int leftSize = ri - ins;

        root->left = solve(
            inorder, postorder,
            ins, ri - 1,
            pos, pos + leftSize - 1,
            inmap,postmap
        );

        root->right = solve(
            inorder, postorder,
            ri + 1, ine,
            pos + leftSize, poe - 1,
            inmap,postmap
        );

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int pos=0;
        int ins=0;
        int poe=n-1;
        int ine=n-1;
        map<int,int>inmap;
        map<int,int>postmap;
        for(int i=0;i<n;i++){
            inmap[inorder[i]]=i;
            postmap[postorder[i]]=i;
        }
        return solve(inorder,postorder,ins,ine,pos,poe,inmap,postmap);
        
    }
};