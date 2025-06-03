class Solution {
public:
bool solve(string s, vector<string>& wordDict,int indstart,int indend, vector<vector<int>>&dp,int n){
    if(indstart>n-1)return true;
            if (dp[indstart][indend] != -1) return dp[indstart][indend];
    string temp="";
    for(int i=indstart;i<=indend;i++){
      temp+=s[i];
       if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end()){
        if(solve(s,wordDict,i+1,indend,dp,n))return dp[indstart][indend]=true;
     }
    }
     return dp[indstart][indend] = false;
    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(s,wordDict,0,n-1,dp,n);
    }
};