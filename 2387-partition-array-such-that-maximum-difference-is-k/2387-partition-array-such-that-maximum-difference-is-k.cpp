class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)return 1;
        sort(nums.begin(), nums.end());
        int l=0;
        int r=1;
        int ans=1;
        while(r<n){
            if(nums[r]-nums[l]<=k)r++;
            else{
               ans++;
               l=r;
               r++;

            }

        }
        return ans;
 


      

    }
};