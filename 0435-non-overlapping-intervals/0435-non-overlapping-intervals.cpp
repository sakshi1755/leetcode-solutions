class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int n=intervals.size();
        int ans=0;
        vector<int>prev=intervals[0];
        for(int i=1;i<n;i++){
            int pst=prev[0];
            int pet=prev[1];
            int cst=intervals[i][0];
            int cet=intervals[i][1];
            if(cst<pet){
                ans++;
            }
            else{
                prev=intervals[i];
            }

        }
        return ans;

    }
};