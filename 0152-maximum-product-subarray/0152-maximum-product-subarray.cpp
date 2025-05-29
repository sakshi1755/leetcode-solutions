class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p=1;
        int s=1;
         int n=nums.size();
        int bestp=nums[0];
        int bests=nums[n-1];
       
        for(int i=0;i<n;i++){
          p=p*nums[i];
          s=s*nums[n-i-1];
          bestp=max(p,bestp);
          bests=max(bests,s);
          if(nums[i]==0)p=1;
          if(nums[n-i-1]==0)s=1;
        }
        return max(bestp,bests);
        
    }
};