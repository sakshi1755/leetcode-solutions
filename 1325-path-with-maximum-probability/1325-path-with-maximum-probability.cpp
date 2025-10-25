#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p}); // undirected
        }
        
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});
        
        while(!pq.empty()) {
            double p = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(p < prob[node]) continue; // outdated entry
            
            for(auto [next, edgeProb] : adj[node]) {
                double newProb = p * edgeProb;
                if(newProb > prob[next]) {
                    prob[next] = newProb;
                    pq.push({newProb, next});
                }
            }
        }
        
        return prob[end_node];
    }
};
