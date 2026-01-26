#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findparent(int x, vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x]=findparent(parent[x], parent);
    }

    int findmst(int n, vector<vector<int>>& edges, int ban, int force){
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > pq;

        for(auto &e: edges)
            pq.push({e[2], {e[0], e[1], e[3]}});

        vector<int> parent(n), rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;

        int cost=0, cnt=0;

        if(force!=-1){
            int u=edges[force][0], v=edges[force][1], w=edges[force][2];
            int pu=findparent(u,parent), pv=findparent(v,parent);
            if(pu!=pv){
                parent[pv]=pu;
                cost+=w;
                cnt++;
            }
        }

        while(!pq.empty()){
            int w=pq.top().first;
            int u=pq.top().second[0];
            int v=pq.top().second[1];
            int idx=pq.top().second[2];
            pq.pop();

            if(idx==ban) continue;

            int pu=findparent(u,parent), pv=findparent(v,parent);
            if(pu==pv) continue;

            parent[pv]=pu;
            cost+=w;
            cnt++;
        }

        if(cnt!=n-1) return 1e9;
        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e, ans(2);
        for(int i=0;i<edges.size();i++)
            e.push_back({edges[i][0],edges[i][1],edges[i][2],i});

        int base=findmst(n,e,-1,-1);

        for(int i=0;i<e.size();i++){
            if(findmst(n,e,i,-1)>base)
                ans[0].push_back(e[i][3]);
            else if(findmst(n,e,-1,i)==base)
                ans[1].push_back(e[i][3]);
        }
        return ans;
    }
};
