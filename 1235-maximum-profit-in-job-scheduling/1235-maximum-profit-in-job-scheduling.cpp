class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>times(n);
        for(int i=0;i<n;i++){
            times[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(times.begin(),times.end());
        sort(startTime.begin(),startTime.end());
        vector<int>dp(n+1,-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int take=times[i][2];
            auto next=lower_bound(times.begin(),times.end(), vector<int>{times[i][1],-1,-1});
            if(next!=times.end()){
                take+=dp[next-times.begin()];
            }
            int nottake=dp[i+1];
            dp[i]=max(take,nottake);




        }
        return dp[0];
        

    }
};