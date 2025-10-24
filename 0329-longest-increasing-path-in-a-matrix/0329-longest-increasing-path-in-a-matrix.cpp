class Solution {
public:
    int dfs(int v, vector<int>& isv, vector<vector<int>>& adj) {
        if (isv[v] != -1)
            return isv[v];
        int count = 1;
        if (adj[v].size() == 0)
            return 1;
        for (int i = 0; i < adj[v].size(); i++) {

            count = max(count, 1 + dfs(adj[v][i], isv, adj));
        }
        return isv[v]=count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<int> isv(n * m, -1);
        vector<vector<int>> adj(n * m);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = i * n + j;
                vector<vector<int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                for (int k = 0; k < 4; k++) {
                    int newrow =i+ d[k][0];
                    int newcol = j+d[k][1];
                    if (newrow >= 0 && newrow < m && newcol >= 0 &&
                        newcol < n &&
                        matrix[newrow][newcol] > matrix[i][j]) {
                        adj[v].push_back(newrow * n + newcol);
                    }
                }
            }
        }
       int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = i * n + j;
                long long count;
                if (isv[v] == -1) {
                    ans = max(ans, dfs(v, isv, adj));
                } 
            }
        }
        return ans;
    }
};