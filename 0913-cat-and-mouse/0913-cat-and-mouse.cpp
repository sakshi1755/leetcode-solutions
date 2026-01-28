#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        // color[m][c][t]: result of state (mouse=m, cat=c, turn=t)
        // 0 = draw, 1 = mouse win, 2 = cat win
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2, 0)));

        // degree[m][c][t]: number of moves possible from this state
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));

        queue<array<int,3>> q;

        // Initialize degrees
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][0] = graph[m].size(); // mouse moves
                degree[m][c][1] = graph[c].size(); // cat moves
                for (int x : graph[c]) {
                    if (x == 0) degree[m][c][1]--; // cat cannot go to hole
                }
            }
        }

        // Terminal states
        for (int c = 0; c < n; c++) {
            for (int t = 0; t < 2; t++) {
                if (c == 0) continue;
                color[0][c][t] = 1; // mouse at hole
                q.push({0, c, t});
            }
        }

        for (int m = 1; m < n; m++) {
            for (int t = 0; t < 2; t++) {
                color[m][m][t] = 2; // cat catches mouse
                q.push({m, m, t});
            }
        }

        // Reverse BFS
        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();

            int cur = color[m][c][t];

            if (t == 0) {
                // Previous was cat's turn
                for (int pc : graph[c]) {
                    if (pc == 0) continue;
                    if (color[m][pc][1] != 0) continue;

                    if (cur == 2) {
                        color[m][pc][1] = 2;
                        q.push({m, pc, 1});
                    } else {
                        degree[m][pc][1]--;
                        if (degree[m][pc][1] == 0) {
                            color[m][pc][1] = 1;
                            q.push({m, pc, 1});
                        }
                    }
                }
            } else {
                // Previous was mouse's turn
                for (int pm : graph[m]) {
                    if (color[pm][c][0] != 0) continue;

                    if (cur == 1) {
                        color[pm][c][0] = 1;
                        q.push({pm, c, 0});
                    } else {
                        degree[pm][c][0]--;
                        if (degree[pm][c][0] == 0) {
                            color[pm][c][0] = 2;
                            q.push({pm, c, 0});
                        }
                    }
                }
            }
        }

        return color[1][2][0];
    }
};




