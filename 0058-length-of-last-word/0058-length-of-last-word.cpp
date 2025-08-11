class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int r=n-1;
        while(r>=0 && s[r]==' '){
            r--;
            
        }
        int ans=0;
        int i=r;
        while(i>=0 && s[i]!=' ' ){
            i--;
            ans++;
        }
        return ans;

        
    }
};