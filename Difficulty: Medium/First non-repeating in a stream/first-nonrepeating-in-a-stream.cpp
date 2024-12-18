//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    string FirstNonRepeating(string &s) {
        int n = s.length();
        queue<char> q;
        string ans;
        map<char, int> m;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            m[ch]++;
            if (m[ch] == 1) {
                q.push(ch);
            }

            while (!q.empty() && m[q.front()] > 1) {
                q.pop();
            }

            if (q.empty()) {
                ans.push_back('#');
            } else {
                ans.push_back(q.front());
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends