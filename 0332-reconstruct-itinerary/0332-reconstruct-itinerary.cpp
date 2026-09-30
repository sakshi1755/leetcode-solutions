class Solution {
public:
    void dfs(int i, vector<priority_queue<int, vector<int>, greater<int>>>&adj,
             map<int,string>&mp, map<string,int>&rmp,
             vector<string>&ans, int tt) {

        auto &pq = adj[i];

        while(!pq.empty()) {
            int nt = pq.top();
            pq.pop();

            dfs(nt, adj, mp, rmp, ans, tt);
        }

        ans.push_back(mp[i]);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<int,string>mp;
        map<string,int>rmp;
        map<string,bool>isthere;
        vector<string>all;

        int n=tickets.size();

        for(int i=0;i<n;i++){
            if(!isthere[tickets[i][0]]) {
                all.push_back(tickets[i][0]);
                isthere[tickets[i][0]]=true;
            }

            if(!isthere[tickets[i][1]]) {
                all.push_back(tickets[i][1]);
                isthere[tickets[i][1]]=true;
            }
        }

        sort(all.begin(),all.end());

        int si=0;

        for(int i=0;i<all.size();i++){
            mp[i]=all[i];
            rmp[all[i]]=i;

            if(all[i]=="JFK")
                si=i;
        }

        int tn=all.size();

        vector<priority_queue<int, vector<int>, greater<int>>>adj(tn);

        for(int i=0;i<n;i++){
            int f=rmp[tickets[i][0]];
            int t=rmp[tickets[i][1]];

            adj[f].push(t);
        }

        vector<string>ans;

        dfs(si,adj,mp,rmp,ans,n+1);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};