/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;    
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int n = grid.size();
          int m=grid[0].size();
        vector<vector<bool>> isv(n, vector<bool>(m, false));

        queue<pair<int,int>> q;
        int time=0;
       for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 2) {
            q.push({i, j});
            isv[i][j] = true;
        } else if (grid[i][j] == 0) {
            isv[i][j] = true;  // Mark empty cells as visited
        }
    }
}
// bool allvis=false;
//  for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < m; ++j) {
             


//     }
//  }
        

    //   if(q.empty())return -1;
        q.push({-1,-1});
        while(!q.empty()){
            if(q.front() == make_pair(-1, -1)){
                time++;
                q.pop();
               if(!q.empty()) q.push({-1,-1});
            }
            else{
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x+1<n && !isv[x+1][y]){
                      isv[x+1][y] = true;
                      q.push({x+1,y});
                }
                 if(y+1<m && !isv[x][y+1]){
                      isv[x][y+1] = true;
                      q.push({x,y+1});
                }
                 if(x-1>=0 && !isv[x-1][y]){
                      isv[x-1][y] = true;
                      q.push({x-1,y});
                }
                 if(y-1>=0 && !isv[x][y-1]){
                      isv[x][y-1] = true;
                      q.push({x,y-1});
                }
            }
        }

        for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
             if(!isv[i][j]){
                return -1;
             }
           }
        }
        return time-1;
            



      
        
    }
};
// @lc code=end

