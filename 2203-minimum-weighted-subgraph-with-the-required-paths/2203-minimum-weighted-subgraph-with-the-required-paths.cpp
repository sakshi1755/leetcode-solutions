class Solution {
public:
    void shortestPath(long long node1,vector<long long>&dis,vector<vector<pair<long long,long long>>>&adj) {
       // vector<long long>dis(size,LLONG_MAX);
       priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

        dis[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            long long node=pq.top().second;
            long long dsf=pq.top().first;
            pq.pop();
  if(dsf > dis[node]) continue;

        for(long long i=0;i<adj[node].size();i++){
            long long child=adj[node][i].first;
            long long w=adj[node][i].second;
            if(dsf+w<dis[child]){
                dis[child]=dsf+w;
                pq.push({dis[child],child});
            }
            
        }
        }
        
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<vector<pair<long long,long long>>>adj(n);
         for(long long i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});

        }
           
        vector<vector<pair<long long,long long>>>revadj(n);
         for(long long i=0;i<edges.size();i++){
            revadj[edges[i][1]].push_back({edges[i][0],edges[i][2]});

        }
        vector<long long>dis1(n,LLONG_MAX);
        vector<long long>dis2(n,LLONG_MAX);
        vector<long long>dis3(n,LLONG_MAX);
        shortestPath(dest,dis3,revadj);
        shortestPath(src1,dis1,adj);
        shortestPath(src2,dis2,adj);
        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++){
        if(dis1[i]!=LLONG_MAX && dis2[i]!=LLONG_MAX && dis3[i]!=LLONG_MAX){
            mini=min(dis1[i]+dis2[i]+dis3[i],mini);
        }
        
        }
        if(mini==LLONG_MAX)return -1;
        
         
        return mini;
    }
};