class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum=INT_MAX;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minnum=min(nums[i],minnum);
        }
        int ans=sum-(minnum*(n-1));
        //if(ans==minnum)return 0;
        return ans-minnum;
        
    }
};

// 2 5 6 
// 3 6 6
// 4 7 6
// 5 7 7 
// 6 8 7
// 7 8 8
// 8 9 8
// 9 9 9 
