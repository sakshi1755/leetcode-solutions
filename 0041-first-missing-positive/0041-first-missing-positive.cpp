class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                start=i;
                break;
            }
        }
        int sm=1;
        for(int i=start;i<n;i++){
            if(nums[i]==sm){
                sm++;

            }
            else if(nums[i]>sm)break;
        }
        return sm;
    }
};