class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int n=nums.size();
        map<int,int>f;
        for(int i=0;i<n;i++){
            f[nums[i]]++;
        }
        for(auto& a:f){
            pq.push({a.second,a.first});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};