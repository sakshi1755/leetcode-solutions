class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<pair<string,int>>si(n);
        map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            si[i].first=strs[i];
            sort(si[i].first.begin(),si[i].first.end());
            si[i].second=i;
            mp[si[i].first].push_back(i);

        }
         vector<vector<string>>ans;
        for(auto it:mp){
            vector<string>temp;
            for(int i=0;i<it.second.size();i++){
                temp.push_back(strs[it.second[i]]);

            }
            ans.push_back(temp);
        }
        return ans;

        
    }
};