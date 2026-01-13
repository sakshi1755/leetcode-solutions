class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});

        }
        for(int i=0;i<n;i++){
            distance[i][i]=0;
           // vector<bool>isvisited(n,0);
           priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

            q.push({0,i});
            while(!q.empty()){
                int curd=q.top().first;
                int no=q.top().second;
                q.pop();
                int m=adj[no].size();
                for(int j=0;j<m;j++){
                    int child=adj[no][j].first;
                    int w=adj[no][j].second;
                    if(distance[i][child]>curd+w){
                        distance[i][child]=curd+w;
                        q.push({distance[i][child],child});
                    }
                }

            }

        }
        int ans=0;
        int maxcity=INT_MAX;
        for(int i=0;i<n;i++){
            int curc=0;
            for(int j=0;j<n;j++ ){
                if(distance[i][j]<=distanceThreshold){
                    curc++;
                }
            }
            if(curc<=maxcity){
                ans=i;
                maxcity=curc;
            }
        }
        return ans;
        
    }
};