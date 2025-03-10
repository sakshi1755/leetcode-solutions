//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  bool find(priority_queue<int>& pq, int target) {  // Pass by reference to avoid copying
     priority_queue<int> temp = pq;  // Copy manually for correct checking
     while (!temp.empty()) {
        if (temp.top() == target) {
            return true;  // Element found
        }
        temp.pop();  // Continue searching
    }
    return false;   // Element not found
  }

  int kthLargest(vector<int> &arr, int k) {
      priority_queue<int> q;
      
      int n = arr.size();
      for (int i = 0; i < n; i++) {
          q.push(arr[i]);
      }

      for (int i = 0; i < n; i++) {
          int sum=arr[i];
          for (int j = i + 1; j < n; j++) {
              sum = sum + arr[j];
            //   if (!find(q, sum)) {  // Corrected find() function usage
                  q.push(sum);
            //   }
          }
      }

      for (int i = 1; i < k; i++) {
          q.pop();
      }

      return q.top();
  }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends