class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) return false;

        int ts=0;
        int n=nums.size();
        for(int i=0; i<n;i++){
            ts+=nums[i];
        }
        if(ts%2!=0)return 0;
        int target=ts/2;
        
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));//dp[i][j] gives me index i tak target pura hota ki nhi ..like true ya false 
        for(int i=0;i<n;i++){
            for(int j=0;j<=target;j++){
                if(j==0)dp[i][j]=true;
                else if(i==0){
                    
                if(j==nums[0])dp[0][j]=true;
                }
                else{
                    bool take=false;
                 if(nums[i]<=j) take=dp[i-1][j-nums[i]];
                    bool nottake=dp[i-1][j];
                    dp[i][j]=take||nottake;
                }
            }
        }
    return dp[n-1][target];
    }
};