class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>freq;
        int l=0;
        int r=0;
        int ans=0;
        int n=nums.size();
        while(r<n){
            if(freq[nums[r]]<k){
                 ans=max(ans, r-l+1);
                freq[nums[r]]++;
                r++;

                       
            }
            else{
                
                freq[nums[l]]--;
                l++;
            }
        }
        return ans;
        
    }
};