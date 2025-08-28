class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        map<int ,int>freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &p:freq){
           pq.push({p.second, p.first});
        }
        
        int i=0;
        while(k>0 && !pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            p.first--;
            if(p.first>0)pq.push({p.first,p.second});
            k--;
          
            
        }
        return pq.size();
       
    }
};