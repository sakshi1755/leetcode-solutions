class Solution {
public:
   int findsubtreechanges(vector<int>&dp,vector<set<int>>&adj,vector<vector<int>>&con,vector<int>&parent,int i){
        //if(con[i].size()==1)return dp[i]=0;
        if(dp[i]!=-1)return dp[i];
        int val=0;
        for(int j=0;j<con[i].size();j++){
            if(con[i][j]!=parent[i]){
                parent[con[i][j]]=i;
                if(!adj[i].count(con[i][j]))val+=1;
                val+=findsubtreechanges(dp,adj,con,parent,con[i][j]);
            }

        }
        return dp[i]=val;


   }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int>dp(n,-1);
        vector<set<int>>adj(n);
        vector<vector<int>>con(n);
        vector<int>parent(n,-1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].insert(edges[i][1]);
            con[edges[i][0]].push_back(edges[i][1]);
            con[edges[i][1]].push_back(edges[i][0]);
        }
        findsubtreechanges(dp,adj,con,parent,0);
        vector<int>ans(n);
        ans[0]=dp[0];
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int t=q.front();
            q.pop();
        for(int j=0;j<con[t].size();j++){
            int i=con[t][j];
            if(i!=parent[t]){

            int parentcontri=ans[parent[i]]-dp[i];
            if(adj[i].count(parent[i]))parentcontri--;
            else parentcontri++;
            ans[i]=dp[i]+parentcontri; 
            q.push(i);
            }
        }
        }
        return ans;

        
    }
};