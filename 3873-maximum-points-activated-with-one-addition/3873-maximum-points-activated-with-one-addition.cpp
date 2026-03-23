class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        vector<pair<int,int>>p;
        int n=points.size();
        for(int i=0;i<n;i++){
            p.push_back({points[i][0],points[i][1]});
        }
        sort(p.begin(),p.end());
        map<pair<int,int>,vector<pair<int,int>>>adj;
        for(int i=0;i<n-1;i++){
            if(p[i].first==p[i+1].first){
                adj[p[i]].push_back(p[i+1]);
                adj[p[i+1]].push_back(p[i]);
            }
        }
        sort(p.begin(),p.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;

        });
        for(int i=0;i<n-1;i++){
            if(p[i].second==p[i+1].second && p[i].first!=p[i+1].first){
                adj[p[i]].push_back(p[i+1]);
                adj[p[i+1]].push_back(p[i]);
            }
        }

        map<pair<int,int>,bool>isv;
        queue<pair<int,int>>q;
        int maxi=0;
        int semaxi=0;
        for(int i=0;i<n;i++){
            if(isv[p[i]])continue;
            int con=0;
            q.push(p[i]);
            isv[p[i]]=true;
            con++;
            while(!q.empty()){
                pair<int,int> t=q.front();
                q.pop();
                for(auto j: adj[t]){
                    if(!isv[j]){
                        q.push(j);
                        isv[j]=true;
                        con++;


                    }
                }

            }
            if(con>=maxi){
                semaxi=maxi;
                maxi=con;
            }
            else if(con>semaxi){
                semaxi=con;
            }





        }
        int ans=1+maxi+semaxi;
        return ans;
        
        
    }
};