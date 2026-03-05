class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        char cc='1';
        long long tempans=0;
        for(int i=0;i<n;i++){
            if(s[i]!=cc)tempans++;
           cc=( cc=='1')?'0':'1'; 
        }
        cc='0';
        long long ans=0;
           for(int i=0;i<n;i++){
            if(s[i]!=cc)ans++;
           cc=( cc=='1')?'0':'1'; 
        }
        ans=min(tempans,ans);
        return ans;
    }
};