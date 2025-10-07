class Solution {
public:
    long long sum(vector<int>& nums, int d){
        long long ans=0;
        long long n=nums.size();
        for(long long i=0;i<n;i++){
            ans=ans+(nums[i]/d);
            if(nums[i]%d!=0)ans++;


        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=1;
        int r=nums[n-1];
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long a=sum(nums,mid);
            if(a<=threshold){
                ans=mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }
        }
        return ans;
        








        
    }
};