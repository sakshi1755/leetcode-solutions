class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int noofz=0;
        int mul=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
               noofz++;
            }
            else mul=mul*nums[i];
        }
        vector<int>ans(n,0);
        if(noofz>1)return ans;
        for(int i=0;i<n;i++){
            if(nums[i]==0 ){
                ans[i]=mul;
            }
            else{
                if(noofz==1)ans[i]=0;
                else ans[i]=mul/nums[i];
            }
        }
        return ans;
    }
};