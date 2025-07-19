class Solution {
  public:
  void dfs(int r, vector<vector<int>> &adj  // Correct adjacency list for an unweighted graph
,vector<int>&parent,vector<int>&low,vector<bool>&isv,int &timer,vector<int> &result,vector<int>&dt){
isv[r]=true;
int m=adj[r].size();
int children=0;
for(int i=0;i<m;i++){
   int neigh=adj[r][i];
   
   if(!isv[neigh]){
       children++;
       dt[neigh]=++timer;
       low[neigh]=timer;
       parent[neigh]=r;
       dfs(neigh,adj,parent,low,isv,timer,result,dt);  
       low[r]=min(low[neigh],low[r]);
       if(parent[r]!=-1 && low[neigh]>=dt[r]){
         result.push_back(r);
       }
       
   }
   else if(neigh!=parent[r]){
       low[r]=min(low[r],low[neigh]);
   }
  }
     if(parent[r] == -1 && children > 1) {
       result.push_back(r);    
     }
    // if(parent[r]!=-1){
    //  for(int i=0; i<m;i++){
    //      int neigh=adj[r][i];
    //      if(low[neigh]>=dt[r]){
    //          result.push_back(r);
    //          break;
    //      }
         
    //  }
    //   }
   


}

  
  
    vector<int> articulationPoints(int v, vector<vector<int>>& edges) {
        // Code here
             vector<vector<int>> adj(v);  // Correct adjacency list for an unweighted graph

        for(int i=0; i<edges.size();i++){
            int u=edges[i][0];
            int v2=edges[i][1];
            adj[u].push_back(v2);
            adj[v2].push_back(u);
             }
             
              
    
    vector<int>dt(v,-1);
    vector<int>low(v,-1);
    vector<int>parent(v,-1);
    vector<bool>isv(v,false);
    vector<int>result;
   
       int timer=0;
    for(int i=0;i<v;i++){
        if(!isv[i]){
              dt[i]=timer;
           low[i]=timer;
       
            dfs(i,adj,parent,low,isv,timer,result,dt);
        }
    }
//   for(int j=0;j<v;j++){  
//  if(parent[j]==-1) {  int child=0;
//     for(int i=0;i<adj[j].size();i++){
//         int l=low[adj[j][0]];
//         if(l!=low[adj[j][i]])child=1;
//     }
//   if(child) result.insert(result.begin(), j);}
// }
   if (result.empty()) return {-1};

// Make sure result is sorted and has unique values
sort(result.begin(), result.end());
result.erase(unique(result.begin(), result.end()), result.end());

return result;
    
    }
};