class Solution {
public:
    string ls;
    vector<bool> gs = vector<bool>(150, false);

    long long dp[16][11][150][2][2][2][2]; // ind,prev,sum,tight,started,inc,dec

    long long solve(int ind, int prev, int sum, int tight, int started, int inc, int dec) {
        if (ind == ls.size()) {
            if (!started)
                return 0;
            bool good = inc || dec;
            bool sumgood = gs[sum];
            return good || sumgood;
        }

        if (dp[ind][prev + 1][sum][tight][started][inc][dec] != -1)
            return dp[ind][prev + 1][sum][tight][started][inc][dec];

        long long res = 0;
        int limit = tight ? ls[ind] - '0' : 9;

        for (int i = 0; i <= limit; i++) {
            int ntight = (tight && (i == limit));

            if (!started && i == 0) {
                res += solve(ind + 1, -1, 0, ntight, 0, 1, 1);
            } else {
                int ninc = inc;
                int ndec = dec;

                if (started) {
                    if (i <= prev)
                        ninc = 0;
                    if (i >= prev)
                        ndec = 0;
                }

                res += solve(ind + 1, i, sum + i, ntight, 1, ninc, ndec);
            }
        }

        return dp[ind][prev + 1][sum][tight][started][inc][dec] = res;
    }

    long long ff(long long l) {
        ls = to_string(l);
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, 0, 1, 0, 1, 1);
    }

    bool isgood(int x) {
        string t = to_string(x);
        bool inc = true;
        bool dec = true;

        for (int i = 0; i < (int)t.size() - 1; i++) {
            if (t[i] >= t[i + 1]) inc = 0;
            if (t[i] <= t[i + 1]) dec = 0;
        }

        return inc || dec;
    }

    long long countFancy(long long l, long long r) {
        for (int i = 0; i < 150; i++) {
            gs[i] = isgood(i);
        }

        long long fn = ff(l-1 );
        long long fr = ff(r);
        return fr - fn;
    }
};