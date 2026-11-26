class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=2;
        int l=0;
        int r=0;
        int currgcd=0;
        int product=1;
        
        while(r<n){
            while(__gcd(product,nums[r])!=1){
                product/=nums[l];
                l++;
            }
            if(__gcd(product,nums[r])==1){
                product*=nums[r];
                ans=max(ans,r-l+1);


            }
            r++;
            
        }
        return ans;
    }
};