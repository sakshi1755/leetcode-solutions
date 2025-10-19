#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
 int c;
 list<pair<int,int>>dq;
 map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity) {
        c=capacity;
        
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){

            int ans=(*(mp[key])).second;
            dq.splice(dq.begin(),dq,mp[key]);
            return ans;
            

        }
        else return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
           (*mp[key]).second=value;
            dq.splice(dq.begin(),dq,mp[key]);
            return ;

        }
        else{
            if(mp.size()==c){
                auto oldkey=dq.back().first;
                dq.pop_back();
                mp.erase(oldkey);
            }
            dq.push_front({key,value});
            mp[key]=dq.begin();
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */