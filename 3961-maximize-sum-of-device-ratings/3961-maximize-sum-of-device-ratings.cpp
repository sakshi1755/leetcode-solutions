class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long n = units.size();
        long long m = units[0].size();
          sort(units[0].begin(), units[0].end());
        long long mini = units[0][0];
        long long mi=0;
        long long secondsmini=units[0][0];
        if(m>=2)secondsmini=units[0][1];
        vector<long long>seconds(n);
        long long ans=0;
        for (int i = 0; i < n; i++) {
            sort(units[i].begin(), units[i].end());
            if(m>=2)seconds[i]=units[i][1];
            else seconds[i]=units[i][0];
            if(mini>units[i][0]){
                mini=units[i][0];
              
            }
            if(secondsmini>seconds[i]){
                secondsmini=seconds[i];
                mi=i;
            }
            ans+=seconds[i];

        }
        ans-=seconds[mi];
        ans+=mini;
        return ans;
    }
};