class Solution {
public:
   void bfs(vector<vector<int>>& image,int color,int sr,int sc,vector<vector<int>>&isv,int n,int m,int ic){
                isv[sr][sc]=true;
                image[sr][sc]=color;
                if(sr+1<n && !isv[sr+1][sc] && image[sr+1][sc]==ic )bfs(image,color,sr+1,sc,isv,n,m,ic);
                if(sr-1>=0 && !isv[sr-1][sc] && image[sr-1][sc]==ic )bfs(image,color,sr-1,sc,isv,n,m,ic); 
                if(sc+1<m && !isv[sr][sc+1] && image[sr][sc+1]==ic )bfs(image,color,sr,sc+1,isv,n,m,ic);
                if(sc-1>=0 && !isv[sr][sc-1] && image[sr][sc-1]==ic )bfs(image,color,sr,sc-1,isv,n,m,ic);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image[0].size();
        int n=image.size();
        int ic=image[sr][sc];
        vector<vector<int>>isv(n,vector<int>(m,false));
        bfs(image, color, sr, sc,isv,n,m,ic);
        return image;
    }
};