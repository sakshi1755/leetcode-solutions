class Twitter {
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp;

public:
    Twitter() {
       timestamp=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<tweets[userId].size();i++){
           pq.push(tweets[userId][i]);
        }

        for(int x:following[userId]){
             for(int i=0;i<tweets[x].size();i++){
           pq.push(tweets[x][i]);
        }
        }
        vector<int>ans;
        for(int i=0;!pq.empty() && i<10;i++){
            int t=pq.top().second;
            ans.push_back(t);
            pq.pop();
        }
        return ans;



        

        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */