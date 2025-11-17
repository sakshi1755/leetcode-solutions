class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int d=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]){
                if(d<k)return false;
                d=0;

            }
            else if(d!=INT_MAX) d++;
        }
        return true;
        
    }
};