class Solution {
public:
    vector<int>solve(int n,vector<int>arr){
        int size=arr.size();
        vector<int>ans;
        bool isnpre=false;
        for(int i=0;i<size;i++){
            int ele=2*arr[i]-1;
            if(ele<=n)ans.push_back(ele);
            if(ele==n)isnpre=true;
            
        }
         for(int i=0;i<size;i++){
            int ele=2*arr[i];
            if(ele<=n)ans.push_back(ele);
            if(ele==n)isnpre=true;
            
        }
        if(isnpre)return ans;
        else{
            return solve(n,ans);
        }
    }
    vector<int> beautifulArray(int n) {
        vector<int>arr={1};

        return solve(n, arr);
        
    }
};