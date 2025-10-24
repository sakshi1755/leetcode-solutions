class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //int n=connections.size();
        vector<vector<int>>adjacencylist(n);
         vector<vector<int>>towardme(n);
        
        queue<int>q;
        vector<bool>isv(n,false);
        q.push(0);
        isv[0]=true;
        for(int i=0;i<n-1;i++){
            adjacencylist[connections[i][0]].push_back(connections[i][1]);
            if(connections[i][1]==0){q.push(connections[i][0]);
            isv[connections[i][0]]=true;}
           towardme[connections[i][1]].push_back(connections[i][0]);
        }
        long long ans=0;
        
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int i=0;i<adjacencylist[t].size();i++){
                if(!isv[adjacencylist[t][i]]){
                    q.push(adjacencylist[t][i]);
                    isv[adjacencylist[t][i]]=true;
                    ans++;
                }
            }
              for(int i=0;i<towardme[t].size();i++){
                if(!isv[towardme[t][i]]){
                    q.push(towardme[t][i]);
                    isv[towardme[t][i]]=true;
                   
                }
            }
            



        }
        return ans;



        
    }
};