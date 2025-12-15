class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        string ans="";
        for(int i=n-1;i>0;i--){
            if(memcmp(s.c_str(),s.c_str()+n-i,i)==0){
                ans=s.substr(0,i);
                break;
            }
        }
       
        

        return ans;
    }
};
