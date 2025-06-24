/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colour(n,0);
        vector<bool>vis(n,false);
        queue<int>q;
        for(int i=0;i<n;i++){
           if(!vis[i]) {
              if(colour[i]==0)  colour[i]=1;
                vis[i]=true;
                q.push(i);
                
            }
            while(!q.empty()){
             int f=q.front();
                q.pop();
                for(int j=0;j<graph[f].size();j++){
                    int child=graph[f][j];
                    if(colour[f]==1){
                        if(colour[child]==1)return false;
                    }
                    if(colour[f]==2){
                        if(colour[child]==2)return false;
                    }
                    if(!vis[child]){
                        vis[child]=true;
                        q.push(child);
                        if(colour[f]==1) {
                        
                            colour[child]=2;

                        } else {
                            colour[child]=1;
                        }
                    }

            }

        }

    }
     return true;  
    }
};
// @lc code=end

