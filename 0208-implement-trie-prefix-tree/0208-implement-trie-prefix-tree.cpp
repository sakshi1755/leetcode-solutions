class Trie {
public:
    Trie* child[26];
    bool isend;
    
    Trie() {
        isend=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }

        
            
    }
    
    void insert(string word) {
        int n=word.size();
        if(child[word[0] - 'a'] == nullptr)
          child[word[0] - 'a'] = new Trie();

        Trie* root=child[word[0]-'a'];
        for(int i=1;i<n;i++){
            int ind=word[i]-'a';
            if(root->child[ind]==nullptr){
                root->child[ind]=new Trie();
            }
            root=root->child[ind];

        }
        root->isend=true;


        
    }
    
    bool search(string word) {
        int n=word.size();
        if(child[word[0] - 'a'] == nullptr)
          return false;

        Trie* root=child[word[0]-'a'];
        for(int i=1;i<n;i++){
            int ind=word[i]-'a';
            if(root->child[ind]==nullptr){
                return false;
            }
            root=root->child[ind];

        }
        return root->isend;        
        
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        if(child[prefix[0] - 'a'] == nullptr)
          return false;

        Trie* root=child[prefix[0]-'a'];
        for(int i=1;i<n;i++){
            int ind=prefix[i]-'a';
            if(root->child[ind]==nullptr){
                return false;
            }
            root=root->child[ind];

        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */