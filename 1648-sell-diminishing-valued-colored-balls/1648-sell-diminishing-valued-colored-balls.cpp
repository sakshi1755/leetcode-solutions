class Solution {
public:
    int mod = 1e9 + 7;
    long long sum(long long i) {
        long long i1 = i + 1;
        if (i % 2 == 0)
            i = i / 2;
        else
            i1 = i1 / 2;
        long long ans = i * i1;
        return ans % mod;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        int n = inventory.size();
        long long high = inventory[0];
        long long low = 0;
        long long k = 0;
        long long ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long c = 0;
            for (int i = 0; i < n; i++) {
                if (inventory[i] > mid)
                    c += (inventory[i] - mid);
            }
            if (c < orders) {
                high = mid - 1;
            } else {
                low = mid + 1;
                k = mid;
            }
        }
        long long c = 0;

        // sell all values strictly greater than k+1
        for (int i = 0; i < n; i++) {
            if (inventory[i] > k + 1) {
                ans += (sum(inventory[i]) - sum(k + 1) + mod) % mod;
                ans %= mod;
                c += inventory[i] - (k + 1);
            }
        }

        // remaining orders are sold at value k+1
        long long remaining = orders - c;

        ans += (remaining % mod) * ((k + 1) % mod) % mod;
        ans %= mod;

        return ans;
    }
};