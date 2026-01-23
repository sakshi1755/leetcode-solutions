class Solution {
public:
 
    class Trie{
        public:
        Trie * links[26];
        bool isend;
        Trie() {
            isend = false;
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }
    };
       using t=Trie *;
    Trie * root=new Trie();
    void inserttrie(string &word){
        t curr=root;
        for(int i=0;i<word.size();i++){
            int indx=word[i]-'a';
            if(!curr->links[indx]){
                curr->links[indx]= new Trie();
            }
            curr=curr->links[indx];

        }
        curr->isend=true;


    }
    string ans="";
    string longestWord(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            inserttrie(words[i]);
        }
        string path="";
        solve(path,root);
        return ans;


    }
    void solve(string &path, t root){
        if(path.length()>ans.length()){
            ans=path;
        }
        for(int i=0;i<26;i++){
            if(root->links[i] && root->links[i]->isend==true){
                path.push_back('a'+i);
                solve(path,root->links[i]);
                path.pop_back();
            }
            
        }

    }
};