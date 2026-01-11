class Solution {
public:
    bool isvalid(string &s, int si,int ei){
        bool ans=true;
        int l=si;
        int r=ei;
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int solve(string &s, int si, vector<int>&dp ){
        int n=s.size();
        if(si == n) return -1;

        if(si>=n || si==n-1)return 0;
        if(dp[si]!=-1)return dp[si];
        int tempans=INT_MAX;
        for(int i=si;i<n;i++){
            if(isvalid(s,si,i)){
                tempans=min(tempans,solve(s,i+1,dp)+1);
            }
        }
        return dp[si]= tempans;
    }
    
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve( s,0,dp);
        
    }
};