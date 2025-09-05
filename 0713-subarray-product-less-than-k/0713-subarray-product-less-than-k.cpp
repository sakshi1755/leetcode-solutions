class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        long long  mul=1;
        int count=0;
        while(r<n){
          mul=mul*nums[r];
          if(mul<k){
            count=count+r-l+1;

            r++;

          }
          else{
            while(mul>=k && l<=r){
               mul=mul/nums[l];
               l++;
              

            }
             count=count+r-l+1;
             r++;

          }
            

        }
        return count;
        
    }
};