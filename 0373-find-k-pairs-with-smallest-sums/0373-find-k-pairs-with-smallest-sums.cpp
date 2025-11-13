class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        // min-heap: {sum, i, j}
        using T = pair<long long, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        // push only (nums1[0] + nums2[j], 0, j) for first k j's
        for (int j = 0; j < nums2.size() && j < k; j++) {
            pq.push({ (long long)nums1[0] + nums2[j], {0, j} });
        }

        while(k-- && !pq.empty()) {
            auto [sum, p] = pq.top();
            pq.pop();
            
            int i = p.first;
            int j = p.second;

            ans.push_back({nums1[i], nums2[j]});

            // push next row element (i+1, j)
            if (i + 1 < nums1.size()) {
                pq.push({ (long long)nums1[i+1] + nums2[j], {i+1, j} });
            }
        }

        return ans;
    }
};
