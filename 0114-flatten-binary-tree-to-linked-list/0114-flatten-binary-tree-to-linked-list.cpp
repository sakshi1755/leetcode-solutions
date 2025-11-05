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
    pair<tn, tn> solve(tn root) {
        if (root == nullptr)
            return {nullptr, nullptr};
        if (root->right == nullptr && root->left == nullptr)
            return {root, root};
        if (root->left == nullptr) {
           auto[rh,rt]= solve(root->right);
            root->right=rh;
            return {root, rt};
        }
        if (root->right == nullptr) {
            auto[lh,lt]=solve(root->left);
            root->right = lh;
            root->left = nullptr;
            return {root, lt};
        }
        auto [rh, rt] = solve(root->right);
        auto [lh, lt] = solve(root->left);
        lt->right = rh;
        root->right = lh;
        root->left = nullptr;
        return {root, rt};
    }
    void flatten(TreeNode* root) {
        solve(root);
        // return root;
    }
};