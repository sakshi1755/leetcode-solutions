class Solution {
public:
    int mod=1e9+7;
    long long ways(int pos,int steps,vector<vector<long long>>&dp,int arrLen){
        if(pos>=arrLen)return 0;
        if(pos<0)return 0;
        if(steps==0 && pos!=0)return 0;
        if(steps==0 && pos==0)return 1;

        if(dp[pos][steps]!=-1)return dp[pos][steps];
       long long right=ways(pos+1,steps-1,dp,arrLen)%mod;
       long long left=ways(pos-1,steps-1,dp,arrLen)%mod;
       long long stay=ways(pos,steps-1,dp,arrLen)%mod;
        return dp[pos][steps]=(right+left+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<long long>>dp(min(501,arrLen),vector<long long>(steps+1,-1));
        return ways(0,steps,dp,arrLen);
        
    }
};