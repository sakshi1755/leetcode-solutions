class Solution {
public:
    int findlengthfromzero(vector<int>&parent, vector<int>&u0,int i,string &s){
        if(u0[i]!=0)return u0[i];
        if(i==0)return u0[0];
        int nn=s[i]-'a';
        int en=findlengthfromzero(parent,u0,parent[i],s);
        u0[i]=en^(1<<nn);
        return u0[i];





    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        vector<int>u0(n,0);
        for(int i=0;i<n;i++){
            findlengthfromzero(parent,u0,i,s);
        }
        map<int,int>f;
        for(int i=0;i<n;i++){
            f[u0[i]]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int nn=f[u0[i]];
            f[u0[i]]--;
            ans+=f[u0[i]];
            for(int j=0;j<26;j++){
                int wn= u0[i] ^(1<<j);
                ans+=f[wn];
            }


        }
        return ans;

        
        
    }
};