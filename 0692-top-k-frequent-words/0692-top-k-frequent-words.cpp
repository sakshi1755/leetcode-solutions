class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        map<string,int>f;
        for(int i=0;i<n;i++){
            f[words[i]]++;
        }
        vector<string>ans(k);
        vector<pair<int,string>>temp;
        for(auto it:f){
            
                temp.push_back({it.second,it.first});
            
        }
        
        sort(temp.begin(),temp.end(),[](pair<int,string>a,pair<int,string>b){
            if(a.first==b.first)return a<b;
            else return a>b;

        });

        for(int i=0;i<k;i++){
            ans[i]=temp[i].second;
        }
        return ans;
        
    }
};