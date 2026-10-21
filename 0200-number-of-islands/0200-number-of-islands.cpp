class Solution {
public:
    using ll = long long;
    vector<ll> parent;
    vector<ll> rank;
    long long findparent(int i) {
        if (parent[i] != i)
            return parent[i] = findparent(parent[i]);
        else
            return i;
    }
    void unite(ll i, ll j) {
        ll pi = findparent(i);
        ll pj = findparent(j);
        if (rank[pj] > rank[pi])
            swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj])
            rank[pi]++;
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int t=m*n;
        parent.resize(t);
        rank.resize(t,0);
        for(int i=0;i<t;i++){
            parent[i]=i;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]=='0')continue;
                int code = i * n + j;
                if (j + 1 < n && grid[i][j + 1] == '1') {
                    int nc = i * n + j + 1;
                    unite(nc, code);
                }
                if (i + 1 < m && grid[i + 1][j] == '1') {
                    int nc = (i + 1) * n + j;
                    unite(nc, code);
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int code = i * n + j;
                if(grid[i][j]=='1' && findparent(code)==code)ans++;
            }
        }
        return ans;
    }
};