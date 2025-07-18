class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int ns=newInterval[0];
        int ne=newInterval[1];
        int n=intervals.size();
        int i=0;
       
            while(i<n &&intervals[i][1]<ns){ans.push_back(intervals[i]);
            i++;}
            if(i<n){
            int cs=intervals[i][0];
            int ce=intervals[i][1];
            if(cs>ne){
                ans.push_back(newInterval);
                while(i<n){
                ans.push_back(intervals[i]);
                i++;
                }
            }
            else{
                vector<int>temp(2);
                temp[0]=min(cs,ns);
                temp[1]=max(ce,ne);
               
                while(i<n && intervals[i][0]<=temp[1]){
                    temp[1]=max(temp[1],intervals[i][1]);
                    i++;
                }
                ans.push_back(temp);
                 while(i<n){
                ans.push_back(intervals[i]);
                i++;
                }
            }
            }
            else ans.push_back(newInterval);
            return ans;
        
        
    }
};