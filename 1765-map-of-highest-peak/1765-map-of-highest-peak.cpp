#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> h(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    h[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if(ni >= 0 && ni < m && nj >= 0 && nj < n && h[ni][nj] == -1) {
                    h[ni][nj] = h[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return h;
    }
};
