/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<bool>isrowzero(n, false);
        vector<bool>iscolzero(m, false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    isrowzero[i]=true;
                    iscolzero[j]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isrowzero[i] || iscolzero[j]){
                    matrix[i][j]=0;
                }
            }
        }
        
        
    }
};
// @lc code=end

