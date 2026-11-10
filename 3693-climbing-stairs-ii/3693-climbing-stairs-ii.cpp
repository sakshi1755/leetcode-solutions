class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=3;j++){
                if(i+j>n)break;
                int newcost=INT_MAX;
                if(dp[i+j]!=INT_MAX)newcost=costs[j+i-1]+(j*j)+dp[i+j];
                dp[i]=min(dp[i],newcost);
            }
        }
        return dp[0];
        
    }
};