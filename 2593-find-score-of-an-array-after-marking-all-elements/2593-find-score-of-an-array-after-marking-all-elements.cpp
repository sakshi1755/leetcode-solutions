class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<long long, long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});

        }
        vector<bool>ismarked(n,false);
        long long sum=0;
        while(!pq.empty()){
            while(!pq.empty() && ismarked[pq.top().second]){
                pq.pop();
            }
            if(!pq.empty()){
                long long val=pq.top().first;
                long long ind=pq.top().second;
                pq.pop();
                sum+=val;
                ismarked[ind]=true;
               if(ind-1>=0) ismarked[ind-1]=true;
               if(ind+1<n)ismarked[ind+1]=true;
            }

        }
        return sum;
    }
};