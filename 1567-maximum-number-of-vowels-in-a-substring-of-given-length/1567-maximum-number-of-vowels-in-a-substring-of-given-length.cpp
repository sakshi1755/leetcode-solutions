class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int c=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u' ){
                c++;
            }
        }
        int ans=c;
        int l=0;
        int r=k-1;
        l++;
        r++;
        while(r<n){
            if(s[l-1]=='a' || s[l-1]=='e' || s[l-1]=='i' || s[l-1]=='o'|| s[l-1]=='u' ){
                c--;
            }
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o'|| s[r]=='u' ){
                c++;
            }
            ans=max(ans,c);
            l++;
            r++;



            
        }
        return ans;
        
    }
};