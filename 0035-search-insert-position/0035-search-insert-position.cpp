class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int h=n-1;
        while(l<h){
                int mid=l+(h-l)/2;
                if(nums[mid]==target)return mid;
                else if(nums[mid]<target)l=l+1;
                else h=mid-1;
        } 
       if(target>nums[l]) return l+1;
       else return l;
        
    }
};