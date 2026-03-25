class Solution {
public:
    long long solve(long long l,long long r,string &s, int encCost,int flatCost,vector<long long>&p){
        long long length=r-l+1;
        long long x=p[r+1]-p[l];
        long long  whole=0;
        if(x==0){
            whole=flatCost;

        }
        else{
            whole=length*x*encCost;
        }
        if(length%2==1){
            return whole;

        }
        else{
            long long part=solve(l,l+(length)/2-1,s,encCost,flatCost,p)+solve(l+(length)/2,r,s,encCost,flatCost,p);
            long long ans=min(part,whole);
            return ans;
        }
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n=s.size();
        vector<long long>p(n+1,0);
        p[0]=0;
        for(int i=1;i<=n;i++){
            p[i]=p[i-1]+(s[i-1]-'0');
        }
        
        long long ans=solve(0,n-1,s,encCost,flatCost,p);
        return ans;
    }
};