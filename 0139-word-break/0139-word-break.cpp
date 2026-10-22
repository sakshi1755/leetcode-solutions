class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string>st;
        int wn=wordDict.size();
        for(int i=0;i<wn;i++){
            st.insert(wordDict[i]);
        }
        vector<bool>dp(n+1,false);
        dp[n] = true;
        for(int i=n-1;i>=0;i--){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(st.count(temp)){
                    dp[i]=dp[j+1];
                }
                if(dp[i])break;
            }
        }
        return dp[0];
        
    }
};