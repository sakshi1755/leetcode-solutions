class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char,long long>ic;
        long long tc=0;
        int n=cost.size();
        
        for(int i=0;i<n;i++){
            ic[s[i]]+=cost[i];
            tc+=cost[i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long ta=tc-ic[s[i]];
            ans=min(ans,ta);


        }
        return ans;
        
    }
};