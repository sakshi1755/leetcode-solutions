bool comp (vector<int> &a, vector<int> &b) {
    return a[1]<b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort (pairs.begin(),pairs.end(),comp);
        int n = pairs.size();
        int count=0;

        int tempEnd = INT_MIN;
        for (int i=0; i<n; i++) {
            if (tempEnd < pairs[i][0]) {
                count++;
                tempEnd = pairs[i][1];
            }

        }

        return count;
    }

};