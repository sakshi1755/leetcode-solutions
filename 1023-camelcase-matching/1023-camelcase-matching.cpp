class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n=queries.size();
        vector<bool>ans(n,false);
        for(int i=0;i<n;i++){
            string word=queries[i];
            int wi=0;
            int wn=word.size();
            int pn=pattern.size();

            int pi=0;
            while(wi<wn && pi<pn){
                if(word[wi]==pattern[pi]){
                    wi++;
                    pi++;
                }
                else{
                    if(word[wi]>='a' && word[wi]<='z')wi++;
                    else break;
                }
            }
            while(wi<wn){
                if(word[wi]>='a' && word[wi]<='z')wi++;
                else break;
            }
            if(wi==wn && pi==pn)ans[i]=true;

        }
        return ans;
        
    }
};