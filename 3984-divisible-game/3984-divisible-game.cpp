class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        vector<long long> primefactors;
        vector<int> primes;

        long long n = nums.size();
        long long mod = 1e9 + 7;

        int maxi = *max_element(nums.begin(), nums.end());

        // Faster sieve
        vector<bool> isnotprime(maxi + 1, false);

        for (int i = 2; i <= maxi; i++) {
            if (!isnotprime[i]) {
                primes.push_back(i);
                if (1LL * i * i <= maxi) {
                    for (long long j = 1LL * i * i; j <= maxi; j += i) {
                        isnotprime[j] = true;
                    }
                }
            }
        }

        set<long long> used;

        // Collect distinct prime factors
        for (int x : nums) {
            int t = x;
            for (int p : primes) {
                if (1LL * p * p > t)
                    break;
                if (t % p == 0) {
                    used.insert(p);
                    while (t % p == 0)
                        t /= p;
                }
            }
            if (t > 1)
                used.insert(t);
        }

        for (auto x : used)
            primefactors.push_back(x);

        if (primefactors.empty())
            primefactors.push_back(2);

        long long maxidiff = LLONG_MIN;
        long long k = LLONG_MAX;

        for (long long prime : primefactors) {
            vector<int> tempnums(n);

            for (int i = 0; i < n; i++) {
                if (nums[i] % prime == 0)
                    tempnums[i] = nums[i];
                else
                    tempnums[i] = -nums[i];
            }

            long long sum = 0;

            for (int r = 0; r < n; r++) {
                sum += tempnums[r];

                if (sum > maxidiff) {
                    maxidiff = sum;
                    k = prime;
                } else if (sum == maxidiff && prime < k) {
                    k = prime;
                }

                if (sum < 0)
                    sum = 0;
            }
        }

        long long ans = ((k % mod) * ((maxidiff % mod + mod) % mod)) % mod;
        return (int)ans;
    }
};