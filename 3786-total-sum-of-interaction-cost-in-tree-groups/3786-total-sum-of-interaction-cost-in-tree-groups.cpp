class Solution {
public:
    void dfs(int i,vector<long long>&parent,vector<vector<long long>>&cng,vector<vector<long long>>& adj, vector<int>& group){
        if(adj[i].size()==1 && parent[i]==adj[i][0]){
            cng[i][group[i]]++;
            return;
        }
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]!=parent[i]){
                parent[adj[i][j]]=i;
                dfs(adj[i][j],parent,cng,adj,group);
                for(int k=1;k<=20;k++){
                    cng[i][k]+=cng[adj[i][j]][k];
                }
            }
        }
        cng[i][group[i]]++;
        return;
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<long long>>adj(n);
        for(int i=0;i<edges.size();i++){
            long long u=edges[i][0];
            long long v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<vector<long long>>cng(n,vector<long long>(21,0));
        vector<long long>parent(n,-1);
        dfs(0,parent,cng,adj,group);
        long long ans=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int a=u;
            if(parent[v]==u)a=v;
            for(int j=1;j<=20;j++){
                ans+=( (cng[0][j]-cng[a][j])*(cng[a][j]) );



            }
        }
        return ans;


        
    }
};