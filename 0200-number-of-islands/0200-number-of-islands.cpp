#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void doconnections(map<pair<int,int>,bool>& isconnected, vector<vector<char>>& grid, stack<pair<int,int>>& st, int n, int m) {
        while(!st.empty()) {
            vector<int> dir = {1, -1};
            int row = st.top().first;
            int col = st.top().second;
            st.pop();
            for(int i = 0; i < 2; i++) {
                if(row + dir[i] >= 0 && row + dir[i] < m && grid[row + dir[i]][col] == '1' && !isconnected[{row + dir[i], col}]) {
                    isconnected[{row + dir[i], col}] = true;
                    st.push({row + dir[i], col});
                }
                if(col + dir[i] >= 0 && col + dir[i] < n && grid[row][col + dir[i]] == '1' && !isconnected[{row, col + dir[i]}]) {
                    isconnected[{row, col + dir[i]}] = true;
                    st.push({row, col + dir[i]});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        map<pair<int,int>,bool> isconnected;
        stack<pair<int,int>> st;
        long long ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !isconnected[{i, j}]) {
                    isconnected[{i, j}] = true;
                    st.push({i, j});
                    ans++;
                    doconnections(isconnected, grid, st, n, m);
                }
            }
        }
        return ans;
    }
};
