#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({dis,j});
                adj[j].push_back({dis,i});



            }
        }
        vector<bool>ismst(n);
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        q.push({0,0});
    
        int totalcost=0;
        while(!q.empty()){
            int node=q.top().second;
            int c=q.top().first;
            q.pop();
            if(ismst[node])continue;
            totalcost+=c;
            ismst[node]=true;
            
            for(int i=0;i<adj[node].size();i++){
                if(!ismst[adj[node][i].second]){
                    q.push({adj[node][i].first,adj[node][i].second});
                }
            }
            
        }
        return totalcost;



        
    }
};