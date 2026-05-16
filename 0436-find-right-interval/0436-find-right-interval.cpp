class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>start(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            start[i][0]=intervals[i][0];
            start[i][1]=i;
        }
        sort(start.begin(),start.end());
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            auto it=lower_bound(start.begin(),start.end(),vector<int>{intervals[i][1],-1});
            if(it!=start.end()){
                ans[i]=start[it-start.begin()][1];
            }
        }
        return ans;
        
    }
};