class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            if(mp[i]==0)continue;
            if(mp[i]%2==1)ans+=1;
            else ans+=2;
        }        
        return ans;
    }
};
