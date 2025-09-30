class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>netgas(n);
        int sum=0;
        for(int i=0; i<n;i++){
            netgas[i]=gas[i]-cost[i];
            sum+=netgas[i];
        }
        if(sum<0)return -1;
        int ans=0;
        
            int max=0;
            
            for(int i=0;i<n;i++){
                  max=max+netgas[i];
                  if(max<0){
                    max=0;
                    ans=i+1;
                  }
            }
        
        return ans;
        
    }
};