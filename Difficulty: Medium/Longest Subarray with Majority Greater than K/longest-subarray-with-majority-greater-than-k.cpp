//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> first_occurrence;
        int max_len = 0;
        int prefix_sum = 0;

        // Initialize the map with prefix sum 0 at index -1
        first_occurrence[0] = -1;

        for (int i = 0; i < n; ++i) {
            // Transform the array: +1 if arr[i] > k, -1 if arr[i] <= k
            if (arr[i] > k) {
                prefix_sum += 1;
            } else {
                prefix_sum -= 1;
            }

            // If the prefix sum is greater than zero, the subarray from index 0 to i is valid
            if (prefix_sum > 0) {
                max_len = i + 1;
            } else {
                // Check if there is any previous occurrence of (prefix_sum - 1)
                if (first_occurrence.count(prefix_sum - 1)) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }

            // Record the first occurrence of the prefix_sum
            if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
                first_occurrence[prefix_sum] = i;
            }
        }

        return max_len;
    
    }   // Code here
        
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends