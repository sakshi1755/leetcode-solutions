class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            // Missing numbers before arr[i]
            int missing = arr[i] - (i + 1);
            if (missing >= k) {
                return i + k;
            }
        }
        // If kth missing number is beyond the last element
        return n + k;
    }
};
