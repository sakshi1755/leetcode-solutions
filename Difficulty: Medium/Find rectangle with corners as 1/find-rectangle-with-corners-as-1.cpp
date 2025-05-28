class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n=mat[0].size();
        int m=mat.size();
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                 if(mat[i][j]){
                     int l=1;
                while((l+j)<n ){
                  if(mat[i][j+l]){
                      for(int c=i+1;c<m;c++){
                          if(mat[c][j] && mat[c][j+l])return true;
                      }
                      
                  }
                  l++;
                }
                 }
            }
        }
        return false;
        // code here
        
    }
};