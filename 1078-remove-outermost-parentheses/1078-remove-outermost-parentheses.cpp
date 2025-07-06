class Solution {
public:
    string removeOuterParentheses(string s) {
        int start=0;
        int count=0;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;
            if(count==0){
                ans=ans+s.substr(start+1, i - start - 1);
                start=i+1;
                
            }

        }
        return ans;
    }
};
// @lc code=end