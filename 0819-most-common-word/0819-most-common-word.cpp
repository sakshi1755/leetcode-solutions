class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (char& c : paragraph)
            c = tolower(c);
        int bn = banned.size();
        map<string,bool>isbanned;
        for (int i = 0; i < bn; i++) {
            for (char& c : banned[i]) {
                c = tolower(c);
            }
            isbanned[banned[i]]=true;
        }

        vector<string> s;
        string word = "";
        int n=paragraph.size();
        map<string,int>f;
        for (int i = 0; i < n; i++) {
           
            if (paragraph[i]<'a' || paragraph[i]>'z') {
                if (!word.empty()) {
                    s.push_back(word);
                    f[word]++;
                }
                word = "";
            } 
            else 
                word += paragraph[i];
        }
         if (!word.empty()) {
                    s.push_back(word);
                    f[word]++;
                }
        int maxi=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(!isbanned[s[i]] && f[s[i]]>maxi){
                maxi=f[s[i]];
                ans=s[i];
            }
        }
        return ans;
    }
};