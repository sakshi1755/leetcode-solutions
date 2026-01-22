#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    class st {
    public:
        int start, end;
        int sum;
        st *left, *right;

        st(int s, int e) {
            start = s;
            end = e;
            sum = 0;
            left = nullptr;
            right = nullptr;
        }
    };

    st* root = nullptr;

    st* build(int start, int end, vector<int>& nums) {
        if (start > end) return nullptr;

        st* node = new st(start, end);

        if (start == end) {
            node->sum = nums[start];
            return node;
        }

        int mid = start + (end - start) / 2;
        node->left = build(start, mid, nums);
        node->right = build(mid + 1, end, nums);
        node->sum = node->left->sum + node->right->sum;

        return node;
    }

    NumArray(vector<int>& nums) {
        if (!nums.empty())
            root = build(0, nums.size() - 1, nums);
    }

    void updateHelper(st* node, int i, int val) {
        if (node->start == node->end) {
            node->sum = val;
            return;
        }

        int mid = node->start + (node->end - node->start) / 2;

        if (i <= mid)
            updateHelper(node->left, i, val);
        else
            updateHelper(node->right, i, val);

        node->sum = node->left->sum + node->right->sum;
    }

    void update(int index, int val) {
        updateHelper(root, index, val);
    }

    int sumHelper(st* node, int l, int r) {
        if (node->start == l && node->end == r)
            return node->sum;

        int mid = node->start + (node->end - node->start) / 2;

        if (r <= mid)
            return sumHelper(node->left, l, r);
        else if (l > mid)
            return sumHelper(node->right, l, r);
        else
            return sumHelper(node->left, l, mid) +
                   sumHelper(node->right, mid + 1, r);
    }

    int sumRange(int left, int right) {
        return sumHelper(root, left, right);
    }
};
