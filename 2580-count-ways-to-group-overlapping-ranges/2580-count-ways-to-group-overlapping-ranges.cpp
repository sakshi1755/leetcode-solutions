class Solution {
public:
   
    vector<long long>parent;

    vector<long long>rank;
   long long power2(long long a, long long b){
        long long mod=1e9+7;
        long long ans=1;
        while(b){
          if(b&1)ans*=a;
          ans=ans%mod;
          a=a*a;
          a=a%mod;
          b>>=1;
        }
        return ans%mod;
   }
   long long  findparent(long long i){
        if(parent[i]==i){
            return i;
        }
        else{
            return parent[i]=findparent(parent[i]);
        }
    }
    void unite(long long i, long long j){
        long long pi=findparent(i);
        long long pj=findparent(j);
        if(rank[i]<rank[j]){
            swap(pi,pj);
        }
        parent[pj]=pi;
        if(rank[pi]==rank[pj])rank[pi]++;


    }
   int countWays(vector<vector<int>>& ranges) {
        long long n=ranges.size();
        parent.resize(n);
        rank.resize(n);
        for(long long i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        sort(ranges.begin(),ranges.end());
        for(long long i=0;i<n-1;i++){
            if(ranges[i+1][0]<=ranges[i][1]){
                ranges[i+1][1]=max(ranges[i][1],ranges[i+1][1]);
                unite(i,i+1);
            }
        }
        long long difgroup=0;
        for(long long i=0;i<n;i++){
            if(findparent(i)==i)difgroup++;
        }
        long long ans=power2(2,difgroup);
        return ans;
        
    }
};