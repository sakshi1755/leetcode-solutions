class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>>pq;
        set<int>available;
        vector<int>server(k,0);
        int n=arrival.size();
        for(int i=0;i<k;i++){
            available.insert(i);
        }
        for(int i=0;i<n;i++){
            int tofind=i%k;
            while(!pq.empty()){
                int time=abs(pq.top().first);
                if(time>arrival[i])break;
                available.insert(pq.top().second);
                pq.pop();
            }
            if(available.empty())continue;
            auto it=available.lower_bound(tofind);
            if(it==available.end()){
                it=available.begin();
            }
            server[*it]++;
            
            pq.push({-arrival[i]-load[i],*it});
            available.erase(it);


            
        }
        vector<int> ans;
        int maxi=0;
        for(int i=0;i<k;i++ ){
            if(server[i]>maxi){
                maxi=server[i];
                
            }
        }
        for(int i=0;i<k;i++){
            if(server[i]==maxi){
                ans.push_back(i);
            }
        }
        return ans;

        
    }
};