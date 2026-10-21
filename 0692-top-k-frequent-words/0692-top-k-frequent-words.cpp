class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        map<string, int>f;
        for(int i=0;i<n;i++){
            f[words[i]]++;
        }
        vector<string>v;
          for (auto x : f) {
            v.push_back(x.first);
        }
        sort(v.begin(),v.end(),[&](string a, string b){
            if(f[a]==f[b]){
                return a<b;
            }
            else{
             return  f[a]>f[b];
            }
        });
        vector<string>ans;

        for(int i=0;i<k;i++){
            ans.push_back(v[i]);
        }
        return ans;
        
    }
};