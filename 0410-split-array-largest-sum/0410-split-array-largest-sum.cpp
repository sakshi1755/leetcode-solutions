class Solution {
public:
  long long partitions(vector<int>& nums, int maxsum ){
    int n=nums.size();
    int p=0;
    long long curr=0;
    for(int i=0;i<n;i++){
        if(curr+nums[i]<=maxsum){
            curr+=nums[i];
        }
        else{
            p++;
            if(nums[i]>maxsum)return INT_MAX;
            curr=nums[i];
        }

    }
    return p+1;

   }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
       long long l=*max_element(nums.begin(),nums.end());
       long long r=accumulate(nums.begin(), nums.end(),0);
       long long ans=0;
        while(l<=r){
           long long mid=l+(r-l)/2;
           long long p=partitions(nums,mid);
            if(p<=k){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }


        }
        return ans;
        
    }
};