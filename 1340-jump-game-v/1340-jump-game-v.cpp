/*
 * @lc app=leetcode id=1340 lang=cpp
 *
 * [1340] Jump Game V
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dfs(int i,vector<vector<int>>&adj,vector<bool>&dfsvisited,vector<long long>&dp){
        if(dp[i]!=-1) return dp[i];
        long long maxconnected=1;
        for(auto &it:adj[i]){
            if(!dfsvisited[it]){
                dfsvisited[it]=true;
                maxconnected=max(maxconnected,1+dfs(it,adj,dfsvisited,dp));
                dfsvisited[it]=false;
            }
        }
        return dp[i]=maxconnected;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+d && j<n;j++){
                if(arr[j]<arr[i]){
                    adj[i].push_back(j);
                }
                else{
                    break;
                }
            }
            for(int j=i-1;j>=i-d && j>=0;j--){
                if(arr[j]<arr[i]){
                    adj[i].push_back(j);
                }
                else{
                    break;
                }
            }
        }
        long long totalmaxconnected=0;
        vector<long long>dp(n,-1);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                long long maxconnected=0;
                queue<int>q;
                q.push(i);
                visited[i]=true;
                vector<bool>dfsvisited(n,false);
                dfsvisited[i]=true;
                totalmaxconnected=max(totalmaxconnected,dfs(i,adj,dfsvisited,dp));
                
            }
        }
        return totalmaxconnected;
    }
};
// @lc code=end

