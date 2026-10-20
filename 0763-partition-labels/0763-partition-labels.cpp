class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,int>mp;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            int c=s[i]-'a';
            if(mp.find(c)==mp.end()){
                mp[c]=i;
            }
        }
        int sp=0;
        int lp=0;
     //   int n=s.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i>lp){
                ans.push_back(lp-sp+1);
                sp=i;
                lp=i;
                
            }
            lp=max(lp,mp[s[i]-'a']);
        }
        ans.push_back(lp-sp+1);
        return ans;

        
    }
};