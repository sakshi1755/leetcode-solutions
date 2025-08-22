class Solution {
public:
    void dfs(int n,int k,int num,vector<int>&ans,int l){
        if(l==n)ans.push_back(num);
       
        else{
           int ld = num % 10;
            if(ld+k<=9){
                dfs(n,k,(num*10+(ld+k)),ans,l+1);
            }
            if(ld-k>=0 && k!=0){
                int newnum=num*10+(ld-k);
                dfs(n,k,(newnum),ans,l+1);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        int l=1;
        vector<int>ans;
        for(int i=1;i<=9;i++){
            dfs(n,k,i,ans,l);
        }
        return ans;
    }
};