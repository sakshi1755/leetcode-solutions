class Solution {
public:
 int findparent(int i,vector<int>&parent){
        if(parent[i]==i)return i;
        else{
           return findparent(parent[i],parent);
        }
      
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        map<string,int>m;
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;

        }
        for(int i=0;i<n;i++){
            int t=accounts[i].size();
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else{
                 if(m[accounts[i][j]]==findparent(i,parent)){
                    accounts[i].erase(accounts[i].begin()+j);
                    j=j-1;
                    

                 }
                else{ int pb=findparent(m[accounts[i][j]],parent);
                 int pn=findparent(i,parent);
                 if(pb!=pn){
                      if(rank[pb]==rank[pn]){
                      parent[pn]=parent[pb];
                         rank[pb]++;
                }
                    else if(rank[pb]>rank[pn]){
                        parent[pn]=parent[pb];
                    }
                    else parent[pb]=parent[pn];
                 }
                
                   
                }
                }


            }

        }
        vector<vector<string>>ans;
        for(auto i:m){
          string  mail=i.first;
            if(i.second!=findparent(i.second,parent)) accounts[findparent(i.second,parent)].push_back(mail);
        }
        cout<<parent[1];
        for(int i=0;i<n;i++){
            if(i==findparent(i,parent)){
                sort(accounts[i].begin()+1,accounts[i].end());
                ans.push_back(accounts[i]);
            }
        }
        return ans;
        
    }
};