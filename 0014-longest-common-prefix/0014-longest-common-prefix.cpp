class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string result="";
        int j=0;
        bool t=true;
        while(t){
            int n0=strs[0].size();
            if(j>n0-1)break;
            char temp=strs[0][j];
            for(int i=1;i<n;i++){
                if(j>=strs[i].size() || strs[i][j]!=temp){
                    t=false;
                    break;
                }
          
            }
            if(t) result=result+temp;
            j++;


        }
        return result;

        
    }
};