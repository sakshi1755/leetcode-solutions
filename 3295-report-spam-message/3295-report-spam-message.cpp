class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,bool>mp;
        int n=bannedWords.size();
        for(int i=0;i<n;i++){
            mp[bannedWords[i]]=true;
        }
        int words=0;
        for(int i=0;i<message.size();i++){
            if(mp[message[i]])words++;
        }
        if(words>=2)return true;
        else return false;
        
    }
};