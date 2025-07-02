class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int t=times[i][2];
            adj[u].push_back({v,t});
        }
        priority_queue<pair<int,int>> q;
        vector<int>lowtime(n,INT_MAX);
        lowtime[k-1]=0;
        q.push({0,k-1});
        while(!q.empty()){
            int f=q.top().second;
            int d=q.top().first;
            q.pop();
            int m=adj[f].size();
            for(int i=0;i<m;i++){
                int child=adj[f][i].first;
                if(d+adj[f][i].second<lowtime[child]){
                    lowtime[child]=lowtime[f]+adj[f][i].second;
                    q.push({lowtime[child],child});
                }
            }

        }
        int maxi=0;
        for(int i=0;i<n;i++){
           maxi=max(maxi,lowtime[i]);

        }
        if(maxi==INT_MAX)return -1;
        else return maxi;
        


        
    }
};