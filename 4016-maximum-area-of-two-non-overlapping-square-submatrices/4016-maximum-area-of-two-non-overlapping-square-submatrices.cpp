class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] +
                             pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }
        int h = min(n, m);
        int l = 0;
        int ans = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            vector<long long> seenrow;
            vector<long long> seencol;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int ti = i + mid-1;
                    int tj = j + mid-1;
                    if (i + mid-1 < m && j + mid-1 < n) {
                        int area = pref[ti + 1][tj + 1] - pref[i][tj + 1] -
                                   pref[ti + 1][j] + pref[i][j];
                        if (area == mid * mid) {
                            seenrow.push_back(i);
                            seencol.push_back(j);
                        }
                    }
                }
            }
            sort(seenrow.begin(), seenrow.end());
            sort(seencol.begin(), seencol.end());
            bool ispossible = false;
            for (int i = 0; i < seenrow.size(); i++) {
                if (lower_bound(seenrow.begin(), seenrow.end(),
                                seenrow[i] + mid) != seenrow.end()) {
                    ispossible = true;
                    break;
                }
            }
            if (!ispossible) {
                for (int i = 0; i < seencol.size(); i++) {
                    if (lower_bound(seencol.begin(), seencol.end(),
                                    seencol[i] + mid) != seencol.end()) {
                        ispossible = true;
                        break;
                    }
                }
            }
            if (ispossible) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans * ans;
    }
};