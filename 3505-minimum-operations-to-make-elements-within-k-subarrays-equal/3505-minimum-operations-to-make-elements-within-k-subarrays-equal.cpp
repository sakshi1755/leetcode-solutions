class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        multiset<int> left, right;
        long long leftsum = 0, rightsum = 0;

        int n = nums.size();
        vector<long long> op(n, LLONG_MAX);

        for (int i = 0; i < n; i++) {
            left.insert(nums[i]);
            leftsum += nums[i];

            while (left.size() > right.size() + 1) {
                int e = *left.rbegin();
                leftsum -= e;
                rightsum += e;
                right.insert(e);
                left.erase(prev(left.end()));
            }

            if (i >= x) {
                int val = nums[i - x];

                if (left.find(val) != left.end()) {
                    left.erase(left.find(val));
                    leftsum -= val;
                } else {
                    right.erase(right.find(val));
                    rightsum -= val;
                }
            }

            while (left.size() > right.size() + 1) {
                int e = *left.rbegin();
                leftsum -= e;
                rightsum += e;
                right.insert(e);
                left.erase(prev(left.end()));
            }

            while (right.size() > left.size()) {
                int e = *right.begin();
                rightsum -= e;
                leftsum += e;
                left.insert(e);
                right.erase(right.begin());
            }

            while (!left.empty() && !right.empty() &&
                   *left.rbegin() > *right.begin()) {
                int a = *left.rbegin();
                int b = *right.begin();

                left.erase(prev(left.end()));
                right.erase(right.begin());

                left.insert(b);
                right.insert(a);

                leftsum += b - a;
                rightsum += a - b;
            }

            if (i >= x - 1) {
                int median = *left.rbegin();

                op[i] = 1LL * median * left.size() - leftsum
                      + rightsum - 1LL * median * right.size();
            }
        }

        vector<vector<long long>> dp(n + 1,
            vector<long long>(k + 1, LLONG_MAX));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != LLONG_MAX &&
                    op[i - 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j],
                        dp[i - x][j - 1] + op[i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};