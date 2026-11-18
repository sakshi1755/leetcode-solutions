class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i%2==1){
                if(s[i-1]!=s[i])ans++;
            }
        }
        return ans;
        
    }
};