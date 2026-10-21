class LRUCache {
public:
    int c;
    map<int,int>mp;
    list<map<int,int>::iterator>li;
    map<int,list<map<int,int>::iterator>::iterator>mp2;
    

    LRUCache(int capacity) {
        c=capacity;
        
    }
    
    int get(int key) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            int ans=it->second;
            auto liit=mp2[it->first];
            li.erase(liit);
            li.push_front(it);
            mp2[key]=li.begin();
              return ans;

        }
        else return -1;
      
        
    }
    
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            it->second=value;
            auto liit=mp2[it->first];
            li.erase(liit);
            li.push_front(it);
            mp2[key]=li.begin();


        }
        else{
            if(li.size()>=c){
                auto it=li.back();
                li.pop_back();
                  mp2.erase(it->first);
                mp.erase(it->first);
              
            }
                mp[key]=value;
                auto it=mp.find(key);
                li.push_front(it);
                mp2[key]=li.begin();

            
          
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */