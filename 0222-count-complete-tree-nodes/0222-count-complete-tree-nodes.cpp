class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int l = findHeightLeft(root);
        int r = findHeightRight(root);

        if(l == r) return (1 << l) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findHeightLeft(TreeNode* node) {
        int h = 0;
        while(node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int findHeightRight(TreeNode* node) {
        int h = 0;
        while(node) {
            h++;
            node = node->right;
        }
        return h;
    }
};
