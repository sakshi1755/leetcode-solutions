class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        string pref="";
        int n=searchWord.size();
        int pn=products.size();
        for(int i=0;i<n;i++){
            pref+=searchWord[i];
            int ind=lower_bound(products.begin(),products.end(),pref)-products.begin();
            int limit=min(ind+3,pn);
            vector<string>temp;
            for(int k=ind;k<limit;k++){
                string word=products[k];
                bool isok=true;
                for(int j=0;j<=i;j++){
                    if(pref[j]!=word[j]){
                        isok=false;
                        break;
                    }
                }
                if(!isok)break;
                temp.push_back(word);
            }
            ans.push_back(temp);
        }
        return ans;

        
    }
};