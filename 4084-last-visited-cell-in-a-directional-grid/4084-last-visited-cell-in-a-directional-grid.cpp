class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>isvisited(m,vector<bool>(n,false));
        vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
        map<char,int>mp;
        mp['L']=0;
        mp['R']=1;
        mp['U']=2;
        mp['D']=3;
        
        int curri=0;
        int currj=0;
        isvisited[curri][currj]=true;
        while(true){
            char currchar=grid[curri][currj];
            int newi=curri+dir[mp[currchar]][0];
            int newj=currj+dir[mp[currchar]][1];
            if(newi>=m || newi<0 || newj>=n || newj<0 || isvisited[newi][newj])return {curri,currj};
            isvisited[newi][newj]=true;
            curri=newi;
            currj=newj;
        }
        return {curri+1,currj+1};

        
    }
};