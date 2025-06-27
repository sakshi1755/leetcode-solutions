/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses, 0);
        for(int i=0;i<m;i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1]; 
            adj[u].push_back(v);  
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int child : adj[node]){
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        else 
        {
            return {};
        }
    }
};
// @lc code=end

