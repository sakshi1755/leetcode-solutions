class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        vector<pair<int,int>>pq;
        priority_queue<int>q;
        for(int i=0;i<n;i++){
            pq.push_back({capital[i],profits[i]});
        }
        sort(pq.begin(),pq.end());
        int ans=0;
        int start=0;
        while(k>0 ){
            while(start<n){
                if(pq[start].first<=w)q.push(pq[start].second);
                else break;
                start++;
            }
            if(!q.empty()){
                w+=q.top();
                q.pop();
           

            }
            else break;
            k--;
           
        }
        return w;
        
        
    }
};