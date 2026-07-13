class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long sum=0;
        long long mod=1e9+7;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long needinc=(sum+k-1)/k;
        needinc--;
        long long needinc1=needinc+1;
        if(needinc%2==0)needinc=needinc/2;
        else needinc1=needinc1/2;
        long long ans=0;
        ans=((needinc%mod)*(needinc1%mod));
        ans%=mod;
        return ans;

    }
};