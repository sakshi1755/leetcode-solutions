class RandomizedSet {
public:
    vector<int>arr;
    map<int,bool>mp;
    map<int,int>idx;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val])return false;
        arr.push_back(val);
        mp[val]=true;
        idx[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp[val])return false;
        int i=idx[val];
        arr[i]=arr.back();
        idx[arr.back()]=i;

        arr.pop_back();

        mp[val]=false;
        return true;

        
    }
    
    int getRandom() {
       // srand(time(0));
        return (arr[rand()%arr.size()]);


        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */