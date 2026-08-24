class Solution {
public:
    int findparent(int i,vector<int>&parent){
        if(parent[i]==i)return i;
        else return parent[i]=findparent(parent[i],parent);
    }
    void unite(int a,int b,vector<int>&rank,vector<int>&parent){
        if(findparent(a,parent)==findparent(b,parent))return;
        int x=findparent(a,parent);
        int y=findparent(b,parent);
        if(rank[x]>=rank[y]){
            parent[y]=x;
            if(rank[x]==rank[y])rank[x]++;

        }
        else{
             parent[x]=y;

        }

    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        map<int,vector<vector<int>>>pos;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pos[matrix[i][j]].push_back({i,j});

            }

        }
        vector<vector<int>>ans(m,vector<int>(n,0));

        

        vector<int>rowsmaxrank(m,0);
        vector<int>colsmaxrank(n,0);
        vector<int>rowmaxvalue(m,0);
        vector<int>colminvalue(n,0);
        for(auto it:pos){
            int value=it.first;
            auto vec=it.second;
            vector<int>parent(n+m,0);
            iota(parent.begin(), parent.end(), 0);
            vector<int>rank(n+m,0);
            int k=vec.size();
            for(int i=0;i<k;i++){
                int x=vec[i][0];
                int y=vec[i][1];
                unite(x,m+y,rank,parent);


            }
            map<int,int>cr;
            for(int i=0;i<k;i++){
                int x=vec[i][0];
                int y=vec[i][1];
                int rx=findparent(x,parent);
                int ry=findparent(y+m,parent);
                cr[rx]=max(cr[rx],rowsmaxrank[x]);
                cr[ry]=max(cr[ry],colsmaxrank[y]);
            }
            for(int i=0;i<k;i++){
                int x=vec[i][0];
                int y=vec[i][1];
                ans[x][y]=1+cr[findparent(x,parent)];           
            }
            for (int i = 0; i < k; i++) {

                int x = vec[i][0];
                int y = vec[i][1];

                rowsmaxrank[x] = max(rowsmaxrank[x], ans[x][y]);
                colsmaxrank[y] = max(colsmaxrank[y], ans[x][y]);
            }

            
        }
        return ans;
        
    }
};