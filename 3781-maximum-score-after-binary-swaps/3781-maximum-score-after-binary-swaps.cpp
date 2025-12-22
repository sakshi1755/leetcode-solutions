class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n=nums.size();
        priority_queue<long long>q;
        long long ans=0;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
            if(s[i]=='1'){
                ans+=q.top();
                q.pop();

            }


        }
        return ans;

        
    }
};