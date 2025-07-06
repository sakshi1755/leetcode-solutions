class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')continue;
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')')count--;
            
                if(count>=ans)ans=count;
            
        }
        return ans;
        
    }
};