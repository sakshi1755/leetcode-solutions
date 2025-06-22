class Solution {

public:

void dfs(int r, vector<vector<int>> &adj  // Correct adjacency list for an unweighted graph
,vector<int>&parent,vector<int>&low,vector<bool>&isv,int &timer,vector<vector<int>> &result,vector<int>&dt){
isv[r]=true;
int m=adj[r].size();
for(int i=0;i<m;i++){
    int node=adj[r][i];
    
    if(dt[node]==-1){
        timer++;
        dt[node]=timer;
        parent[node]=r;
    }
    if(low[node]==-1){
      low[node]=timer;
    }
    if(!isv[node]) dfs(node,adj,parent,low,isv,timer,result,dt);
}
for(int i=0;i<m;i++){
      int node=adj[r][i];
    if(node!=parent[r]){
        if(low[node]<low[r])low[r]=low[node];
    }
}
if (parent[r] != -1 && low[parent[r]] < low[r]) {
    result.push_back({parent[r], r});
}

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<vector<int>> adj(n);  // Correct adjacency list for an unweighted graph

        for(int i=0; i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
             }
            vector<vector<int>> result;
    int timer=0;
    vector<int>dt(n,-1);
    vector<int>low(n,-1);
    vector<int>parent(n,-1);
    vector<bool>isv(n,false);
    dt[0]=0;
    low[0]=0;
    for(int i=0;i<n;i++){
        if(!isv[i]){
            dfs(i,adj,parent,low,isv,timer,result,dt);
        }
    }
     return result;   
    }
};