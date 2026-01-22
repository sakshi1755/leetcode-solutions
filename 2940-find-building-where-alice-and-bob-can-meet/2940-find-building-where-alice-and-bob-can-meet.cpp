class Solution {
public:
    class segtree {
    public:
        int start;
        int end;
        int maxi;
        segtree* left;
        segtree* right;
        segtree(int s, int e) {
            start = s;
            end = e;
            maxi = 0;
            left = nullptr;
            right = nullptr;
        }
    };
    using sn = segtree*;
    sn build(vector<int>& h, int s, int e) {
        if (s == e) {
            sn root = new segtree(s, e);
            root->maxi = h[s];
            return root;
        } else {
            int mid = s + (e - s) / 2;
            sn l = build(h, s, mid);
            sn r = build(h, mid + 1, e);
            sn root = new segtree(s, e);
            root->maxi = max(l->maxi, r->maxi);
            root->left = l;
            root->right = r;
            return root;
        }
    }
    int findleftestmax(sn root, int des, int di, int s, int e) {
        if (!root || e < di)
            return -1;
        if (root->maxi <= des)
            return -1;

        if (s == e) {
            return s;
        }

        int mid = s + (e - s) / 2;

        if (di <= mid) {
            int ans = findleftestmax(root->left, des, di, s, mid);
            if (ans != -1)
                return ans;
            return findleftestmax(root->right, des, di, mid + 1, e);
        } else {
            return findleftestmax(root->right, des, di, mid + 1, e);
        }
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        int n = heights.size();
        int m = queries.size();
        vector<int> ans(m, -1);
        sn root = build(heights, 0, n - 1);
        for (int idx = 0; idx < queries.size(); idx++) {
            int a = queries[idx][0];
            int b = queries[idx][1];

            int l = min(a, b);
            int r = max(a, b);

            if (l == r) {
                ans[idx] = l;
            } else if (heights[r] > heights[l]) {
                ans[idx] = r;
            } else {
                ans[idx] = findleftestmax(root, heights[l], r + 1, 0, n - 1);
            }
        }

        return ans;
    }
};
