/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    using tn = TreeNode*;
    tn solve(vector<int>& preorder, vector<int>& inorder, map<int, int>& inmap,
             int instart, int inend, int prestart, int preend) {
        if (instart > inend)
            return nullptr;
        if (prestart > preend)
            return nullptr;
        int numsleft = inmap[preorder[prestart]] - instart;
        tn root = new   TreeNode(preorder[prestart]);
         root->left =
            solve(preorder, inorder, inmap, instart, inmap[preorder[prestart]] - 1, 
                  prestart + 1, prestart + numsleft);
         root->right =
            solve(preorder, inorder, inmap, inmap[preorder[prestart]] + 1, inend,
                  prestart + numsleft + 1, preend) ;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        if (n == 1){
            tn root = new TreeNode(preorder[0]);
            return root;
        }
        map<int, int> inmap;
        for (int i = 0; i < n; i++) {
            inmap[inorder[i]] = i;
        }
        tn root =
            solve(preorder, inorder, inmap, 0, n-1, 0,
                  n-1);
        return root; // this builds the tree with new info and returns the root
    }
};