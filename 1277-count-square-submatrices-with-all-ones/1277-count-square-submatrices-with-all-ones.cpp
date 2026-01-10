class Solution {
public:
   int solve(vector<int>&h){
    int n=h.size();
    int ans=0;
    for(int i=0;i<n;i++){

          int mh=h[i];
          for(int j=i;j<n;j++){
            if(h[j]==0)break;
            mh=min(mh,h[j]);
            if(mh>=(j-i+1))ans++;
            else break;

          }


    }
    return ans;
  
   }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
           int m=matrix[0].size();
        vector<int>h(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(matrix[i][j]==1) h[j]++;
               else h[j]=0; 
            }
            maxi+=solve(h);

        }
        return maxi;
        
    }
};