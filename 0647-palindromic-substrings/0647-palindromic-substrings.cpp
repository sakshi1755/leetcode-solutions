class Solution {
public:
    bool ispali(string s,int l,int r){
        
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int length=0;length<n;length++){
            for(int i=0;i<n;i++){
                if(i+length>=n)break;
               if( ispali(s,i,i+length))ans++;

            }
        }
        return ans;
    }
};