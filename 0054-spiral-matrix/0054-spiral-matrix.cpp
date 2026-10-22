class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ls = {0, 0};
        vector<int> rs = {0, m - 1};
        vector<int> le = {n - 1, 0};
        vector<int> re = {n - 1, m - 1};
        vector<int> ans;
        vector<vector<bool>> isv(n, vector<bool>(m, false));
        while (ans.size() < n * m) {
            int i = ls[0];
            int j = ls[1];
            for ( j = ls[1]; j <= rs[1]; j++) {
                if (!isv[i][j])
                    ans.push_back(matrix[i][j]);
                isv[i][j] = true;
            }
            j= rs[1];
            for ( i = rs[0]; i <= re[0]; i++) {
                if (!isv[i][j])
                    ans.push_back(matrix[i][j]);
                    isv[i][j] = true;
            }
            i=re[0];
            for ( j = re[1]; j >=le[1]; j--) {
                if (!isv[i][j])
                    ans.push_back(matrix[i][j]);
                isv[i][j] = true;
            }
            j=le[1];
            for ( i = le[0]; i >= ls[0]; i--) {
                if (!isv[i][j])
                    ans.push_back(matrix[i][j]);
                    isv[i][j] = true;
            }
            
            ls = {ls[0] + 1, ls[1] + 1};
            rs = {rs[0] + 1, rs[1] - 1};
            le = {le[0] - 1, le[1] + 1};
            re = {re[0] - 1, re[1] - 1};
        }
        return ans;
    }
};