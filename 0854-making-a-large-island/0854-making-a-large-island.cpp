class Solution {
public:
    int findparent(int i, vector<int>& parent) {
        if (parent[i] == i) return i;
        else return parent[i] = findparent(parent[i], parent);
    }

    void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int x_parent = findparent(x, parent);
        int y_parent = findparent(y, parent);
        if (x_parent == y_parent) return;

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n * n;
        vector<int> parent(n2);
        for (int i = 0; i < n2; i++) {
            parent[i] = i;
        }
        vector<int> rank(n2, 0);

        // Union DSU for connected 1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int m = n * i + j;
                    if (i > 0 && grid[i - 1][j]) {
                        unite(parent, rank, m, n * (i - 1) + j);
                    }
                    if (j > 0 && grid[i][j - 1]) {
                        unite(parent, rank, m, n * i + j - 1);
                    }
                    if (i < n - 1 && grid[i + 1][j]) {
                        unite(parent, rank, m, n * (i + 1) + j);
                    }
                    if (j < n - 1 && grid[i][j + 1]) {
                        unite(parent, rank, m, n * i + j + 1);
                    }
                }
            }
        }

        // Precompute component sizes
        vector<int> componentSize(n2, 0);
        for (int i = 0; i < n2; i++) {
            int root = findparent(i, parent);
            componentSize[root]++;
        }

        // Max size without any change
        int max_size = 0;
        for (int i = 0; i < n2; i++) {
            if (parent[i] == i) {
                max_size = max(max_size, componentSize[i]);
            }
        }

        // Try converting each 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int addsize = 1;
                    unordered_set<int> neighborComponents;

                    if (i > 0 && grid[i - 1][j]) {
                        int girdp = findparent(n * (i - 1) + j, parent);
                        if (!neighborComponents.count(girdp)) {
                            addsize += componentSize[girdp];
                            neighborComponents.insert(girdp);
                        }
                    }
                    if (j > 0 && grid[i][j - 1]) {
                        int girdp = findparent(n * i + j - 1, parent);
                        if (!neighborComponents.count(girdp)) {
                            addsize += componentSize[girdp];
                            neighborComponents.insert(girdp);
                        }
                    }
                    if (i < n - 1 && grid[i + 1][j]) {
                        int girdp = findparent(n * (i + 1) + j, parent);
                        if (!neighborComponents.count(girdp)) {
                            addsize += componentSize[girdp];
                            neighborComponents.insert(girdp);
                        }
                    }
                    if (j < n - 1 && grid[i][j + 1]) {
                        int girdp = findparent(n * i + j + 1, parent);
                        if (!neighborComponents.count(girdp)) {
                            addsize += componentSize[girdp];
                            neighborComponents.insert(girdp);
                        }
                    }

                    max_size = max(max_size, addsize);
                }
            }
        }

        return max_size;
    }
};
