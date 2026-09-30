class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>res(k,0);
        vector<vector<long long>>dp(n+1,vector<long long>(k,0));

        for(int i=n-1;i>=0;i--){
             nums[i]=nums[i]%k;
              dp[i][nums[i] % k]++;
            for(int j=0;j<k;j++){
                //dp[i][j]+=dp[i+1][j];
                long long nk=(j*nums[i])%k;
                dp[i][nk]+=dp[i+1][j];
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++) res[i]+=dp[j][i];
        }
        return res;
    }
};


/// 1 3+1/2=4/2 =2
//1 2 3 4 0 1 
