class Solution {
public:
    int solve(string &temp,vector<vector<int>>&divisor){
        int n=temp.length();
        int ans=INT_MAX;
        for(int i=0;i<divisor[n].size();i++){
            int d=divisor[n][i];
            int tempans=0;
            for(int i=0;i<d;i++){
                int start=i;
                int end=n-d+i;
                while(start<=end){
                    if(temp[start]!=temp[end])tempans++;
                    start+=d;
                    end-=d;
                }

            }
            ans=min(tempans,ans);
        }
        return ans;
    }
    int minimumChanges(string s, int k) {
        int n=s.size();
        vector<vector<int>>divisor(n+1);
        for(int i=1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                divisor[j].push_back(i);
            }
        }
        vector<vector<int>>change(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                change[i][j]=solve(temp,divisor);
                

            }
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MAX));
        dp[n][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int r=1;r<=k;r++){
                for(int j=i;j<n;j++ ){
                    int tempans=INT_MAX;
                    if(dp[j+1][r-1]!=INT_MAX && change[i][j]!=INT_MAX)tempans=change[i][j]+dp[j+1][r-1];
                    dp[i][r]=min(dp[i][r],tempans);
                }

            }
        }
        return dp[0][k];

    }
};
