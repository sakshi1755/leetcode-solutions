/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>redadjacency(n);
        vector<vector<int>>blueadjacency(n);
        for(auto it:redEdges){
            redadjacency[it[0]].push_back(it[1]);
        }
        for(auto it:blueEdges){
            blueadjacency[it[0]].push_back(it[1]);
        }
        vector<int>ans(n,-1);
        queue<pair<int,int>>q;  //red is 1,blue is 2..so which node u have taken till now
        q.push({0,1});
        q.push({0,2});
        ans[0]=0;
        map<pair<int,int>,bool>isvisted;
        isvisted[{0,1}]=true;
        isvisted[{0,2}]=true;
        vector<vector<int>>distance(n,vector<int>(3,INT_MAX));
        distance[0][1]=0;
        distance[0][2]=0;
        while(!q.empty()){
            int n1=q.front().first;
            int p=q.front().second;
            q.pop();
            if(p==1){
                for(int i=0;i<blueadjacency[n1].size();i++){
                    int nn=blueadjacency[n1][i];
                    if(!isvisted[{nn,2}]){
                        isvisted[{nn,2}]=true;
                        distance[nn][2]=distance[n1][p]+1;
                        q.push({nn,2});


                    }
                }
            }
            else{
                     for(int i=0;i<redadjacency[n1].size();i++){
                    int nn=redadjacency[n1][i];
                    if(!isvisted[{nn,1}]){
                        isvisted[{nn,1}]=true;
                        distance[nn][1]=distance[n1][p]+1;
                        q.push({nn,1});


                    }
                }

            }


        }
        for(int i=0;i<n;i++){
            ans[i]=min(distance[i][1],distance[i][2]);
            if(ans[i]==INT_MAX)ans[i]=-1;
        }
        return ans;



    }


        

};
// @lc code=end

