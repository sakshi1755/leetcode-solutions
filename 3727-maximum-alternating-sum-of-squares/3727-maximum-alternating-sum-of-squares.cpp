class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long  n=nums.size();
        long long odd=0;
        long long even=0;
        long long mid=n/2;
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<mid;i++){
            long long temp=nums[i]*nums[i];
            odd+=temp;
            
            
        }
         for(int i=mid;i<n;i++){
            long long temp=nums[i]*nums[i];
            even+=temp;
            
            
        }
        long long ans=even-odd;
        return ans;
        
    }
};