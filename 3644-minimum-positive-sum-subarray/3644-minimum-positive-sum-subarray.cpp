class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;(j-i+1)<=r && j<n;j++){
                sum=sum+nums[j];
                if(j-i+1>=l){
                   if(sum>0) ans=min(ans,sum);
                }
            }

        }
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};