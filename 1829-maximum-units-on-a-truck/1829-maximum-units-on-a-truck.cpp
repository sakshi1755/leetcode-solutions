class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>pq;
        int n=boxTypes.size();
        int ans=0;
        for(int i=0;i<n;i++){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        int k=truckSize;
        while(k>0 && !pq.empty()){
            int units=pq.top().first;
            int boxes=pq.top().second;
            
            pq.pop();
            if(boxes<k){
                ans=units*boxes+ans;
                k=k-boxes;

            }
            else{
                ans=k*units+ans;
                k=0;
                break;
            }
            

        }
        return ans;


        
    }
};