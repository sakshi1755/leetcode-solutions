class Solution {
public:
    // bool istrue(string &s,set<string>&words,int st,int e,int
    // ews,map<string,int>&f){
    //     int i=st;
    //     int count=0;
    //     string ss="";
    //     map<string,int>isseen;

    //     while(i<=e){

    //         count++;
    //         ss+=s[i];

    //         if(count==ews){

    //             if(words.count(ss)){
    //                 isseen[ss]++;
    //                 if(isseen[ss]>f[ss])return false;
    //             }
    //             else return false;
    //             ss="";
    //             count=0;

    //         }
    //         i++;

    //     }
    //     return true;
    // }
    vector<int> findSubstring(string s, vector<string>& words) {
        int nw = words.size();
        int ews = words[0].size();
        int tot = nw * ews;
        vector<int> ans;
        set<string> wordsset;
        map<string, int> f;
        for (int i = 0; i < nw; i++) {
            wordsset.insert(words[i]);
            f[words[i]]++;
        }
        int n = s.size();

        for (int i = 0; i < ews; i++) {
            int currentwordsfound = 0;
            int sp = i;
            map<string, int> seen;
            for (int j = i; j < n; j += ews) {
                if (j + ews > n)
                    break;
                string cs;
                for (int k = j; k < j + ews; k++) {
                    cs += s[k];
                }
                if (wordsset.count(cs)) {

                    currentwordsfound++;
                    seen[cs]++;
                    while (seen[cs] > f[cs]) {
                        string left = s.substr(sp, ews);
                        seen[left]--;
                        currentwordsfound--;
                        sp += ews;
                    }
                    if (currentwordsfound == nw) {
                        ans.push_back(sp);

                        string left = s.substr(sp, ews);
                        seen[left]--;
                        currentwordsfound--;
                        sp += ews;
                    }
                } else {
                    currentwordsfound = 0;
                    seen.clear();
                    sp = j + ews;
                }
            }
        }
        return ans;
    }
};