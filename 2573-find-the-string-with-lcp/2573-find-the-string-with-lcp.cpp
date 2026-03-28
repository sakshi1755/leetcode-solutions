#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   bool checkvalid(vector<vector<int>>& lcp){
        int n = lcp.size();
        int m=lcp[0].size();
        int pos=0;
        while(pos<n){
            if(pos==0){
                if(lcp[0][0]!=n)return false;
                for(int i=1;i<m;i++){
                    if(lcp[pos][i]>(lcp[pos][0]-i)) return false;
                }
            }
            else{
                for(int i=0;i<pos;i++){
                    if(lcp[pos][i]!=lcp[i][pos]) return false;
                }
                for(int i=pos;i<m;i++){
                    if(lcp[pos-1][i-1]==0 ){
                        continue;
                    }
                    else  if(lcp[pos][i]!=lcp[pos-1][i-1]-1) return false;
                }
            }
            pos++;
        }
       
        return true;
    }

    
    string findTheString(vector<vector<int>>& lcp) {
        if(!checkvalid(lcp)) return "";
        int n = lcp.size();

        // 🔥 DSU START (ADDED)
        vector<int> p(n);
        for(int i=0;i<n;i++) p[i]=i;

        function<int(int)> find = [&](int x){
            if(p[x]==x) return x;
            return p[x]=find(p[x]);
        };

        auto unite = [&](int a,int b){
            a=find(a);
            b=find(b);
            if(a!=b) p[b]=a;
        };
        // 🔥 DSU END

        // 🔥 REPLACES YOUR COPYING LOGIC
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(lcp[i][j]>0){
                    unite(i,j);
                }
            }
        }

        // 🔥 assign characters (same idea, just using parent)
        string ans(n,'?');
        char cur='a';
        unordered_map<int,char> mp;

        for(int i=0;i<n;i++){
            int par = find(i);

            if(mp.find(par)==mp.end()){
                if(cur>'z') return "";
                mp[par]=cur++;
            }

            ans[i]=mp[par];
        }
vector<vector<int>> calc(n, vector<int>(n, 0));

for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
        if(ans[i]==ans[j]){
            if(i==n-1 || j==n-1) calc[i][j]=1;
            else calc[i][j]=1+calc[i+1][j+1];
        } else {
            calc[i][j]=0;
        }
    }
}

if(calc != lcp) return "";
        return ans;
    }
};