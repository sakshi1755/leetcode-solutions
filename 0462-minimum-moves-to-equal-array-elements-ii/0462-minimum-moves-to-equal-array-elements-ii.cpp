class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long finalnum;
        if(n%2==2){
            int mid=n/2;
            finalnum=(nums[mid]+nums[mid-1])/2;
        }
        else{
            int mid=n/2;
            finalnum=nums[mid];

        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-finalnum);
        }
        return ans;
        
    }
};

// 1 10 2 9
// 1 8 0 7 
// 1 6 19 20
// 5 0 13 14
// 18  13   0   1