class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      
        vector<int> temp;
        temp.push_back(1);
        
        vector<vector<int>> ans;
        ans.push_back(temp);
          if(numRows==1)return ans;
        temp.clear();
        temp.push_back(1);
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2)return ans;
        for(int i=2; i<numRows;i++){
              vector<int>t(i+1,1);
            for(int j=1; j<i;j++){
          
            t[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(t);
        }
        return ans;




        
    }
};