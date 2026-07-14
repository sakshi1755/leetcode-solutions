class Solution {
public:
    int mod=1e9+7;
    int solve(int gcd1,int gcd2, int i,vector<int>&nums,vector<vector<vector<int>>>&dp){
        
        if(i==nums.size()){
           return gcd1 != 0 && gcd1 == gcd2;;
        }
        if(dp[gcd1][gcd2][i]!=-1){
            return dp[gcd1][gcd2][i];
        }
        long long takein1=solve(__gcd(gcd1,(int)nums[i]),gcd2,i+1,nums,dp)%mod;
        long long takein2=solve(gcd1,__gcd(gcd2,(int)nums[i]),i+1,nums,dp)%mod;
        long long notake=solve(gcd1,gcd2,i+1,nums,dp)%mod;
        long long ans=((takein1+takein2+notake)%mod);
        return dp[gcd1][gcd2][i]=ans;

    }
    int subsequencePairCount(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          maxi= max(maxi, (int)nums[i]);
        }
        vector<vector<vector<int>>>dp(maxi+1,vector<vector<int>>(maxi+1,vector<int>(n+1,-1)));
        return solve(0,0,0,nums,dp);

        
    }
};