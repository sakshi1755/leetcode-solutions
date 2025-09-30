class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev(s.rbegin(),s.rend());
        string ans="";
        for(int i=0;i<n;i++){
            if(memcmp(s.c_str(),rev.c_str()+i,n-i)==0){
                ans=rev.substr(0,i)+s;
                break;
            }
        }
        return ans;
        
    }
};