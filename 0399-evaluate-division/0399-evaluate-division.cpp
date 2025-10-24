class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        map<string,bool>ispresent;
        map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<n;i++){
            string f=equations[i][0];
            string s=equations[i][1];
            float v=values[i];
            ispresent[s]=true;
            ispresent[f]=true;
            adj[f].push_back({s,v});
            adj[s].push_back({f,1/v});

        }
        int m=queries.size();
        vector<double> ans(m,-1);
        for(int i=0;i<m;i++){
            string f=queries[i][0];
            string s=queries[i][1];
            if(f==s && ispresent[f]){
                ans[i]=1;
                continue;
            }
            map<string,bool>isv;
            queue<pair<string,double>>q;
            q.push({f,1});
            isv[f]=true;
            double temp=1;
            while(!q.empty()){
                string curr=q.front().first;
                double curv=q.front().second;
                bool isansfound=false;
                q.pop();
                for(int j=0;j<adj[curr].size();j++ ){
                    string tempchar=adj[curr][j].first;
                    if(tempchar==s){
                        ans[i]=curv*adj[curr][j].second;
                        isansfound=true;
                        break;
                    }
                    if(!isv[tempchar]){
                        isv[tempchar]=true;
                        q.push({tempchar,(curv*adj[curr][j].second)});



                    }
                }
               if( isansfound)break;
            }

        }
        return ans;
    }
};