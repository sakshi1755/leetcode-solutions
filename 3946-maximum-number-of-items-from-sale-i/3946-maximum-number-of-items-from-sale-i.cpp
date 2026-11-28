class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int>val(n,0);
        for(int i=0;i<n;i++){
            int facti=items[i][0];
            for(int j=0;j<n;j++){
                int factj=items[j][0];
                if(i!=j){
                    if(factj%facti==0){
                        val[i]++;
                    }

                }
            }
        }
       int dp[1001][1501][2];
        for(int i=budget;i>=0;i--){
            dp[n][i][0]=0;
              dp[n][i][1]=0;

        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=budget;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k]=dp[i+1][j][0];
                    if(j<items[i][1])continue;
                    int temp=dp[i][j-items[i][1]][1];
                    if(k==0){
                        temp+=(val[i]+1);
                    }
                    else{
                        temp+=1;
                    }
                    dp[i][j][k]=max(dp[i][j][k],temp);
                }
           

                
            }

        }
        return dp[0][budget][0];
    }
};

//6 2
//2 6
//3 4
