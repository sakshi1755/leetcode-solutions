class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (k == 0) return nums;
        if (n < 2 * k + 1) return ans;  // Need at least 2k+1 numbers

        long long sum = 0;
        for (int i = 0; i < 2 * k + 1; i++) {  // Sum first window
            sum += nums[i];
        }

        int i = k;  
        ans[i] = sum / (2 * k + 1);

        // Sliding window
        for (int r = 2 * k + 1; r < n; r++) {
            sum += nums[r];
            sum -= nums[r - (2 * k + 1)];
            i++;
            ans[i] = sum / (2 * k + 1);
        }
        return ans;
    }
};
