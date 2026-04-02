class EventManager {
public:
    priority_queue<vector<int>>pq;
    map<int,int>islive;
    map<int,bool>isactive;
    EventManager(vector<vector<int>>& events) {
        for(int i=0;i<events.size();i++){
            pq.push({events[i][1],-events[i][0]});
            islive[events[i][0]]=events[i][1];
            isactive[events[i][0]]=true;
        }
        
    }
    
    void updatePriority(int eventId, int newPriority) {
        islive[eventId]=newPriority;
        pq.push({newPriority,-eventId});
        


    }
    
    int pollHighest() {
        while(!pq.empty()){
            int p=pq.top()[0];
            int ei=-pq.top()[1];
            pq.pop();
            if(islive[ei]==p && isactive[ei]){
                isactive[ei]=false;
                return ei;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */