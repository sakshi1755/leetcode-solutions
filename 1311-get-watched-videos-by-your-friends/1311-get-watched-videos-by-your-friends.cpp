class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
         vector<int>distance(n,INT_MAX);
         priority_queue<pair<int,int>>q;
         q.push({id,0});
         distance[id]=0;
         while(!q.empty()){
            int node=q.top().first;
            int d=q.top().second;
            q.pop();
            for(int i=0;i<friends[node].size();i++){
                int nn=friends[node][i];
                int w=1;
                
                if(distance[nn]>distance[node]+w){
                    distance[nn]=distance[node]+w;
                    q.push({nn,distance[nn]});
                }
            }
         }
         vector<string>ans;
         set<string>ss;
         map<string,int>freq;
         for(int i=0;i<n;i++){
            if(distance[i]==level){
                for(int j=0;j<watchedVideos[i].size();j++){
                    string temp=watchedVideos[i][j];
                    freq[temp]++;
                if(!ss.count(temp)){
                    ans.push_back(temp);
                    ss.insert(temp);
                }

                }
            }

         }
         sort(ans.begin(),ans.end(),[&](auto &a, auto &b){
            if(freq[a]==freq[b])return a<b;
            else return freq[a]<freq[b];
            
         });
         return ans;

        
    }
};