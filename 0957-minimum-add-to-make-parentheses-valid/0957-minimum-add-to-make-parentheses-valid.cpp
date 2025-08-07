class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(s[i]);
            else{
                if(st.empty())ans++;
                else st.pop();
            }
        }
        ans+=st.size();
        return ans;
        
    }
};