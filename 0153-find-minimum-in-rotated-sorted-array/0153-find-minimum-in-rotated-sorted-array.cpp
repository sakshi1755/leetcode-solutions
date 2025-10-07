class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=INT_MAX;
        if(nums[l]<nums[r]){
            return nums[l];
        }
        while(l<=r){
           long long mid=l+(r-l)/2;
            if(nums[mid]<=nums[r]){
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;


        
    }
};