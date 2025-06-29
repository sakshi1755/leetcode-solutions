/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=    t
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row= heights.size();
        int col= heights[0].size();
        vector<vector<int>>effort(row, vector<int>(col, INT_MAX));
        effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}}); // {effort, {row, col}}
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int height = top.first;
            int r = top.second.first;
            int c = top.second.second;
            if(r+1<row ){
                int tempeffort=max(effort[r][c],abs(heights[r+1][c]-heights[r][c]));
                if(tempeffort<effort[r+1][c]){
                    effort[r+1][c]=tempeffort;
                    pq.push({tempeffort, {r+1, c}});
                }
            }
            if(c+1<col){
                int tempeffort=max(effort[r][c],abs(heights[r][c+1]-heights[r][c]));
                if(tempeffort<effort[r][c+1]){
                    effort[r][c+1]=tempeffort;
                    pq.push({tempeffort, {r, c+1}});
                }
            }
            if(r-1>=0){
                int tempeffort=max(effort[r][c],abs(heights[r-1][c]-heights[r][c]));
                if(tempeffort<effort[r-1][c]){
                    effort[r-1][c]=tempeffort;
                    pq.push({tempeffort, {r-1, c}});
                }
            }
            if(c-1>=0){
                int tempeffort=max(effort[r][c],abs(heights[r][c-1]-heights[r][c]));
                if(tempeffort<effort[r][c-1]){
                    effort[r][c-1]=tempeffort;
                    pq.push({tempeffort, {r, c-1}});
                }
            }
        }
            
         return effort[row-1][col-1];   

        
    }
};
// @lc code=end

