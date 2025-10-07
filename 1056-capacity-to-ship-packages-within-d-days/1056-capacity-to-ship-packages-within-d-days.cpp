class Solution {
public:
    int getdays(vector<int>& weights, int w) {
        int days = 1;       // At least one day needed
        int curr = 0;       // Current day's total weight

        for (int i = 0; i < weights.size(); i++) {
            if (curr + weights[i] <= w) {
                curr += weights[i];
            } else {
                days++;
                curr = weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int d = getdays(weights, mid);
            if (d <= days) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
