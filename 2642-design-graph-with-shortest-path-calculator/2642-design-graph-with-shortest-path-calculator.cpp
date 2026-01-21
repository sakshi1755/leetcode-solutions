class Graph {
public:
    int size;
    vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        size=n;
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});

        }

        
    }
    
    void addEdge(vector<int> edge) {
         
            adj[edge[0]].push_back({edge[1],edge[2]});

        
        
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dis(size,INT_MAX);
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            int node=pq.top().second;
            int dsf=pq.top().first;
            pq.pop();
  if(dsf > dis[node]) continue;

        for(int i=0;i<adj[node].size();i++){
            int child=adj[node][i].first;
            int w=adj[node][i].second;
            if(dsf+w<dis[child]){
                dis[child]=dsf+w;
                pq.push({dis[child],child});
            }
            
        }
        }
        if(dis[node2]==INT_MAX)return -1;
        else return dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */