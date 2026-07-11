class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>a,vector<int>b){
            if(a[0]==b[0]){
                return b[1]<a[1];
            }
            else return a[0]<b[0];
        });
        int ce=intervals[0][1];
        int remove=0;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=ce){
                remove++;
            }
            else ce=intervals[i][1];
        }
        return n-remove;
        
    }
};