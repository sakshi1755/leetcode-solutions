class Solution {
public:
    bool areanagrams(string & word1,string &  word2){
        vector<int>m1(26,0);
        vector<int>m2(26,0);
        for(int i=0;i<word1.size();i++){
            m1[word1[i]-'a']++;
        }
         for(int i=0;i<word2.size();i++){
            m2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(m1[i]!=m2[i])return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1;i<words.size();i++){
           
                if(words[i-1].size()==words[i].size()){
                    if(areanagrams(words[i],words[i-1])){words.erase(words.begin()+i);
                    i--;}
                }

            

        }
        return words;
        
        
    }
};