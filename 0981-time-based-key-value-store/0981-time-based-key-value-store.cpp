class TimeMap {
public:
    map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans="";
        auto it=lower_bound(mp[key].begin(),mp[key].end(), pair<int,string>{timestamp+1, ""});
        if(it==mp[key].begin())return ans;
        else if(it==mp[key].end()) return mp[key].back().second;
        else{
            int id=it-mp[key].begin();
            id--;
            ans=mp[key][id].second;
            return ans;
            
        }
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */