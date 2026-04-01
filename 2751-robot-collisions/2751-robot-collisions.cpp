class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> sortedpos;
        vector<int> ispresent(n, true);
        for (int i = 0; i < n; i++) {
            sortedpos.push_back({positions[i], i});
        }
        sort(sortedpos.begin(), sortedpos.end());
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            int curri = sortedpos[i][1];
            while (!st.empty() && ispresent[curri]) {
                if (directions[curri] =='L'&& directions[st.top().second]=='R') {
                    int topstacki = st.top().second;
                    int topstackh = healths[topstacki];

                    int currh = healths[curri];
                    if (topstackh == currh) {
                        st.pop();
                        ispresent[topstacki] = false;
                        ispresent[curri] = false;
                    } else if (topstackh > currh) {
                        ispresent[curri] = false;
                        healths[topstacki]--;

                    } else {
                        st.pop();
                        healths[curri]--;
                        ispresent[topstacki] = false;
                    }
                } 
                else{
                    break;
                }
            }
            if(ispresent[curri])st.push({directions[curri],curri});
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ispresent[i])ans.push_back(healths[i]);
        }
        return ans;

    }
};