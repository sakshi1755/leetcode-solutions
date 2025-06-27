/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
#include <bits/stdc++.h>`
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1; // Start or end is blocked
        }

        vector<vector<int>>adj(n*n+1);
        vector<int>dist(n*n, INT_MAX);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(i+1<n && grid[i+1][j]==0)adj[i * n + j + 1].push_back((i+1) * n + j + 1);
                    if(j+1<n && grid[i][j+1]==0)adj[i * n + j + 1].push_back(i * n + (j+1) + 1);
                    if(j-1>=0 && grid[i][j-1]==0)adj[i * n + j + 1].push_back(i * n + (j-1) + 1);
                    if(i-1>=0 && grid[i-1][j]==0)adj[i * n + j + 1].push_back((i-1) * n + j + 1);
                    if(j-1>=0 && i-1>=0 && grid[i-1][j-1]==0)adj[i * n + j + 1].push_back((i-1) * n + j-1 + 1);
                    if(j+1<n && i+1<n && grid[i+1][j+1]==0)adj[i * n + j + 1].push_back((i+1) * n + j+1 + 1);
                    if(j-1>=0 && i+1<n && grid[i+1][j-1]==0)adj[i * n + j + 1].push_back((i+1) * n + j-1 + 1);    
                    if(j+1<n && i-1>=0 && grid[i-1][j+1]==0)adj[i * n + j + 1].push_back((i-1) * n + j +1+ 1);
                }
                
            }
        }
        vector<int>distance(n*n+1,INT_MAX);
        vector<bool>isv(n*n+1,false);
        distance[1]=1;
        queue<int> q;
        isv[1]=true;
        q.push(1);
        while(!q.empty()){
            int f= q.front();
            q.pop();
            isv[f]=true;
            for(int i=0;i<adj[f].size();i++){
                int child=adj[f][i];
                if(!isv[child]){
                    distance[child]=distance[f]+1;
                    isv[child]=true;
                     q.push(child);
                }
               
            }
        }
        if(distance[n*n]==INT_MAX)return -1;
        else return distance[n*n];
        
    }
};
// @lc code=end

