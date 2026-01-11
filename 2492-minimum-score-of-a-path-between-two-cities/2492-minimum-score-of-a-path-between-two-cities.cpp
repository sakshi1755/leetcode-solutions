class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]-1].push_back({roads[i][1]-1,roads[i][2]});
            adj[roads[i][1]-1].push_back({roads[i][0]-1,roads[i][2]});

        }
        vector<bool>isvis(n,false);
        queue<int>pq;
        int ans=INT_MAX;
        pq.push(0);
        while(!pq.empty()){
        
            int t=pq.front();
            pq.pop();

                isvis[t]=true;
            for(int i=0;i<adj[t].size();i++){
                ans=min(ans,adj[t][i].second);
                if(!isvis[adj[t][i].first])pq.push(adj[t][i].first);
            }
        }
        return ans;
        
    }
};
