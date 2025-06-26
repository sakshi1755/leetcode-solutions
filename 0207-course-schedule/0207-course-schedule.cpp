/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool dfs(int node, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&dfsvisited){
           vis[node]=true;
           dfsvisited[node]=true;
              for(int i=0;i<adj[node].size();i++){
                int child=adj[node][i];
                if(dfsvisited[child]){
                    return false; // cycle detected
                }
                if(!vis[child]){
                     if(!dfs(child, adj, vis, dfsvisited))return false;
                }
              }

                dfsvisited[node]=false;
                return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<m;i++){
           int v=prerequisites[i][0];
           int u=prerequisites[i][1]; 
           adj[u].push_back(v);  

        }
        vector<bool>dfsvisited(numCourses,false);
        
        vector<bool>vis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
          
             if(!dfs(i,adj,vis,dfsvisited)) return false;   
            }
            
        }
        return true;
    }
    
};


// @lc code=end

