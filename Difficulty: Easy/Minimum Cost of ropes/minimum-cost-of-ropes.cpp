//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
          priority_queue<int, vector<int>, greater<int>> q;
          int n=arr.size();// Min-heap
          for(int i=0; i<n; i++){
              q.push(arr[i]);
          }
         
          int cost=0;
          for(int i=1; i<n; i++){
              int temp=q.top();
              q.pop();
            int temp2=q.top();
              cost=temp+temp2+cost;
              q.pop();
              q.push(temp+temp2);
             
            //  cout<<prev;
          }
          return cost;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends