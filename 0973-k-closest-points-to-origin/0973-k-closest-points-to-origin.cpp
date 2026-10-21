class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            long long d=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({d,i});
        }
        vector<vector<int>>ans;
        while(!pq.empty() && k>0){
            auto t=pq.top();
            int ind=t.second;
            pq.pop();
            k--;
            ans.push_back(points[ind]);
        }
        return ans;
        
    }
};