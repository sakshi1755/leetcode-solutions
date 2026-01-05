class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>back(n,1);
        for(int i=0;i<n;i++)
        back[i]=i;


    int maxlength=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(dp[j]<dp[i]+1){
                        back[j]=i;
                    }
                    dp[j]=max(dp[j],dp[i]+1);
                    maxlength=max(maxlength,dp[j]);

                }

                

            }
        }
        vector<int> ans;
        int idx = -1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==maxlength){
                idx = i;
                break;
            }
        }

        while(back[idx] != idx){
            ans.push_back(nums[idx]);
            idx = back[idx];
        }
        ans.push_back(nums[idx]);

        reverse(ans.begin(), ans.end());
        return ans;


        
        
    }
};