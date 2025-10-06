class Solution {
public:
    void solve(TreeNode* target, int k, vector<int>& ans, unordered_set<TreeNode*>& visited) {
        if (!target || k < 0 || visited.count(target)) return;
        visited.insert(target);
        if (k == 0) {
            ans.push_back(target->val);
            return;
        }
        solve(target->left, k - 1, ans, visited);
        solve(target->right, k - 1, ans, visited);
    }

    void findparent(TreeNode* head, TreeNode* target, TreeNode*& parent) {
        if (!head) return;
        if (head->left == target || head->right == target) {
            parent = head;
            return;
        }
        findparent(head->left, target, parent);
        findparent(head->right, target, parent);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_set<TreeNode*> visited;

        solve(target, k, ans, visited);  // nodes in subtree

        TreeNode* parent = target;

        while (parent != root) {
            TreeNode* nextParent = nullptr;
            findparent(root, parent, nextParent); // find actual parent
            parent = nextParent;
            solve(parent, k - 1, ans, visited);
            k--;
        }

        return ans;
    }
};
