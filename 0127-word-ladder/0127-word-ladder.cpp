/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool differByOne(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                count++;
                if (count > 1) return false;
            }
        }
        return count == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n= wordList.size();
        vector<vector<int>>adj(n+1);
        int endWordindex = -1;
        vector<bool> vis(n+1, false);
        for(int i=0;i<n;i++){
            if(wordList[i] == endWord) {
                endWordindex=i+1;
            }
            if(differByOne(beginWord, wordList[i])){
                adj[0].push_back(i+1);
            }
         
            for(int j=i+1;j<n;j++){
                if(differByOne(wordList[i], wordList[j])){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int> dist(n+1, INT_MAX);
        dist[0] = 1;
        queue<int> q;
        int ans=0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=true;
            if(node == endWordindex) {
                ans = dist[node];
                break;
            }
            for(int i=0;i<adj[node].size();i++){
                int child = adj[node][i];
                if(!vis[child]){
                    dist[child] = min(dist[child], dist[node]+1);
                    q.push(child);
                }
            }   

        }

        return ans ; // +1 for the endWord
    }
};
// @lc code=end

