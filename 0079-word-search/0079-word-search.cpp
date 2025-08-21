/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j, vector<vector<bool>>& isvisited){
        if(index == word.size()) return true; // Found the word
        if(i-1>=0 && !isvisited[i-1][j] && board[i-1][j]==word[index]){
            isvisited[i-1][j]=true;
            if(dfs(board,word,index+1,i-1,j,isvisited)) return true;
            isvisited[i-1][j]=false;
        }
        if(i+1<board.size() && !isvisited[i+1][j] && board[i+1][j]==word[index]){
            isvisited[i+1][j]=true;
            if(dfs(board,word,index+1,i+1,j,isvisited)) return true;
            isvisited[i+1][j]=false;
        }
        if(j-1>=0 && !isvisited[i][j-1] && board[i][j-1]==word[index]){
            isvisited[i][j-1]=true;
            if(dfs(board,word,index+1,i,j-1,isvisited)) return true;
            isvisited[i][j-1]=false;
        }
        if(j+1<board[0].size() && !isvisited[i][j+1] && board[i][j+1]==word[index]){
            isvisited[i][j+1]=true;
            if(dfs(board,word,index+1,i,j+1,isvisited)) return true;
            isvisited[i][j+1]=false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>isvisited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    isvisited[i][j]=true;
                   if( dfs(board,word,1,i,j,isvisited)) return true;
                   isvisited[i][j]=false; // Backtrack if not found
                }

            }
        }
        return false;
    }
};
// @lc code=end

