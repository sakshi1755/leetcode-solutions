class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int h=n-1;
        int ans=-1;
        while(l<=h){
                int mid=l+(h-l)/2;
                if(nums[mid]==target){ans= mid;
                break;
                }
                else if(nums[mid]<target)l=l+1;
                else h=mid-1;
        } 
        if(ans==-1)return {-1,-1};
        vector<int>a;
        int f=ans;
         l=ans;
        while(f>=0 && nums[f]==target){
            f--;
        }
        while(l<n && nums[l]==target){
            l++;
        }
        a={f+1,l-1};
        return a;


        
    }
};