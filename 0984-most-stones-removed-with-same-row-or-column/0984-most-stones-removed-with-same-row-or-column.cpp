class Solution {
public:
    int findparent(int i,vector<int>&parent){
        if(parent[i]==i)return i;
        else{
           return findparent(parent[i],parent);
        }
      
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(int i=0;i<n;i++){
            maxrow=max(maxrow,stones[i][0]);
            maxcol=max(maxcol,stones[i][1]);
        }
        int p=maxrow+maxcol+2;
        vector<int>parent(p);
        vector<int>rank(p,0);
        for(int i=0;i<p;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int r=stones[i][0];
            int c=stones[i][1]+maxrow+1;
            int pr=findparent(r,parent);
            int pc=findparent(c,parent);
            if(rank[pr]==rank[pc]){
                parent[pc]=pr;
                rank[pr]++;
            }
            else if(rank[pr]>rank[pc]){
                parent[pc]=pr;
            }
            else parent[pr]=pc;

        }
        int vp=0;
        for(int i=0;i<p;i++){
            if(rank[i]>=1 && parent[i]==i)vp++;
        }
        return n-vp;

        
    }
};