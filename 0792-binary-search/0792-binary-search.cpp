class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            if(nums[low]==target)return low;
            int mid=low +(high-low)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target) low=mid+1;
            else high=mid-1;
            
        }
        return -1;
    }
};