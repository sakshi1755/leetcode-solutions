class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int n=s.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push('(');
            if(s[i]==')'){
                if(i+1>=n || s[i+1]!=')'){
                    ans++;
                }
                else{
                    i++;
                }
                if(!st.empty())st.pop();
                else ans++;
            }
        }
        ans+=(2*st.size());
        return ans;
    }
};