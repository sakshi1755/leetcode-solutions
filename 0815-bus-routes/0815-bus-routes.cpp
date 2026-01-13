class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, vector<int>> bcr;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                bcr[routes[i][j]].push_back(i);
            }
        }

        if (source == target) return 0;

        map<int, bool> seenStop;
        vector<bool> seenRoute(routes.size(), false);

        queue<pair<int,int>> q; // stop, buses taken
        q.push({source, 0});
        seenStop[source] = true;

        while (!q.empty()) {
            auto [t, w] = q.front();
            q.pop();

            for (int r : bcr[t]) {
                if (seenRoute[r]) continue;
                seenRoute[r] = true;          // taking this bus
                for (int bn : routes[r]) {
                    if (bn == target) return w + 1;
                    if (!seenStop[bn]) {
                        seenStop[bn] = true;
                        q.push({bn, w + 1});
                    }
                }
            }
        }

        return -1;
    }
};
