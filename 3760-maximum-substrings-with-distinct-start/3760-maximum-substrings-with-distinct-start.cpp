class Solution {
public:
    int maxDistinct(string s) {
        int n=s.size();
        map<char,int>d;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(d[s[i]]==0)ans++;
            d[s[i]]++;
        }
        return ans;

        
    }
};