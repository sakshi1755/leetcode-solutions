/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,int n,int m) {
  vis[i][j] = true;
  if(i+1<n && grid[i+1][j]==1 && !vis[i+1][j]) {
    dfs(grid, vis, i+1, j, n, m);
  } 
    if(j+1<m && grid[i][j+1]==1 && !vis[i][j+1]) {
        dfs(grid, vis, i, j+1, n, m);
    }
    if(i-1>=0 && grid[i-1][j]==1 && !vis[i-1][j]) {
        dfs(grid, vis, i-1, j, n, m);
    }
    if(j-1>=0 && grid[i][j-1]==1 && !vis[i][j-1]) {
        dfs(grid, vis, i, j-1, n, m);
    }


}
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    dfs(grid, vis, i, j,n,m);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
    return count;
    }
};
// @lc code=end

