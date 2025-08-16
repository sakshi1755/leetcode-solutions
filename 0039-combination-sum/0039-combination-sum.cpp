#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path, res);
        return res;
    }

    void dfs(vector<int>& candidates, int start, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break; // pruning
            path.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], path, res); // allow reuse by passing i
            path.pop_back();
        }
    }
};
