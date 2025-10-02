class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];

        }
        vector<bool>inc(n,false);
        inc[0]=true;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])inc[i]=true;
            else break;
        }
        vector<bool>dec(n,false);
        dec[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1])dec[i]=true;
            else break;
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n-1;i++){
            if(inc[i] && dec[i+1]){
                ans=min(ans,abs(prefix[i]-(prefix[n-1]-prefix[i])));
            }
        }
        if(ans==LLONG_MAX)return -1;
        return ans;
        
    }
};