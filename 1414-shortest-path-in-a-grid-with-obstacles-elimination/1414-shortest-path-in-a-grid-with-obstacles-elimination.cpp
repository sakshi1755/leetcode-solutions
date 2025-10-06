#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return 0; // trivial case

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
        queue<tuple<int,int,int>> q; // i, j, remaining k
        q.push({0,0,k});
        visited[0][0][k] = true;
        int steps = 0;

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int sz = q.size();
            steps++;
            for(int t=0; t<sz; t++){
                auto [i,j,rem] = q.front(); q.pop();
                for(auto d : dirs){
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n){
                        int newRem = rem - grid[ni][nj];
                        if(newRem < 0) continue;
                        if(ni == m-1 && nj == n-1) return steps; // reached destination
                        if(!visited[ni][nj][newRem]){
                            visited[ni][nj][newRem] = true;
                            q.push({ni,nj,newRem});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
