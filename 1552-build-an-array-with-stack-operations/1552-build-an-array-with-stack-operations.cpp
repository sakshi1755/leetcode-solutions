class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        map<int,bool>mp;
        int m=target.size();
        
        for(int i=0;i<m;i++){
            mp[target[i]]=true;

        }
        int last=target[m-1];
        vector<string>ans;
        for(int i=1;i<=last;i++){
            if(mp[i]){
                ans.push_back("Push");

            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");



            }
            
        }
        return ans;

        
    }
};