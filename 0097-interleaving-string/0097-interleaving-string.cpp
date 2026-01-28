
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int t=s3.length();
        int i=0;
        int j=0;
        int k=0;
        if(t!=n+m)return false;
        vector<vector<vector<bool>>>dp(t+1,vector<vector<bool>>(n+1,vector<bool>(m+1,false)));
        for(int i=0;i<t+1;i++){
            for(int j=0;j<n+1;j++){
                for(int k=0;k<m+1;k++){
                    if(i==0 && j==0 && k==0)dp[i][j][k]=true;
                    if(k+j!=i)dp[i][j][k]=false;
                    else{
                        if(i>0 && j>0 && s3[i-1]==s1[j-1])dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]);
                        if(i>0 && k>0 &&s3[i-1]==s2[k-1])dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]);
                        
                    }


                }
            }
        }    
        return dp[t][n][m];
        
    }
};