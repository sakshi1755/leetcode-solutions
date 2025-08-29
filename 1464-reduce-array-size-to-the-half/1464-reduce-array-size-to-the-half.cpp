class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>freq;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            
        }
        for(auto &p:freq){
            pq.push(p.second);
        }
        int k=(n+1)/2;
        int ans=0;
        while(k>0){
            int f=pq.top();
            pq.pop();
            k=k-f;
            ans++;
        }
        return ans;




        
    }
};