class Solution {
public:
    void dfs(int node,vector<bool>&issafe,vector<bool>&isvisted,vector<vector<int>>& graph, vector<int>&ans){
         int m=graph[node].size();
        isvisted[node]=true;
         for(int i=0;i<m;i++){
            int child=graph[node][i];
           
            if(!isvisted[child] && !issafe[child]){
                dfs(child,issafe,isvisted,graph,ans);
            }
         }
        for(int i=0;i<m;i++){
            int child=graph[node][i];
            if(!issafe[child]){
               return ;
               
            }
        }
        issafe[node]=true;
        ans.push_back(node);  
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outdegree(n,0);
        vector<bool>issafe(n,false);
        vector<int>ans;
        for(int i=0; i<n;i++){
            int m=graph[i].size();
            outdegree[i]=m;
            if(m==0){
                ans.push_back(i);
                issafe[i]=true;
            }
        }
   //     vector<bool>issafe(n,false);
        vector<bool>isvisted(n,false);
        for(int i=0;i<n;i++){
          if(!isvisted[i] && !issafe[i]){
           dfs(i,issafe,isvisted,graph,ans);
          }
        }
    sort(ans.begin(),ans.end());
    return ans;
    }
};