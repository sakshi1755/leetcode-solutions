class Solution {
public:
    int minOperations(string s) {
        string ss=s;
        map<char,int>f;
     
        sort(ss.begin(),ss.end());
        if(s==ss)return 0;
        int n=s.size();
           for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        if(n==2)return -1;
        if(s[0]==ss[n-1] && f[s[0]]==1 && f[s[n-1]]==1 && s[n-1]==ss[0])return 3;
        if(s[0]==ss[0] || s[n-1]==ss[n-1])return 1;
        else return 2;
        
    }

};