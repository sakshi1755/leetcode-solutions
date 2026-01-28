class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        int ans=1;
        for(int i=1;i<=mini;i++){
         if(mini%i==0 && maxi%i==0)ans=max(ans,i);
        }
        return ans;

        
    }
};