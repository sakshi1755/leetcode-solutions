/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, int& dis, int& extraedges) {
              visited[node] = 1;
              for(int i = 0; i < adj[node].size(); i++) 
              { if(visited[adj[node][i]] ) extraedges++;
                if(!visited[adj[node][i]]) {
                    dfs(adj, visited, adj[node][i], dis,extraedges);
                }
              }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int dis=0;
        int extraedges=0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i, dis, extraedges);
                dis++;
            }
        }
        //cout<<extraedges/2<< "  "<<dis;
       if((extraedges/2 -1) < dis-1) return -1;
       return dis-1;  
    }
};
// @lc code=end

