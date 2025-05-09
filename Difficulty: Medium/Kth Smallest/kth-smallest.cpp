//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // // arr : given array
    // void heapify(vector<int> &arr, int i, int k){
    //     int largest=i;
    //     int l=2*i+1;
    //     int r=2*i+2;
    //     if(l<k && arr[l]>arr[largest]){
    //         largest=l;
    //     }
    //      if(r<k && arr[r]>arr[largest]){
    //         largest=r;
    //     }
    //     if(largest!=i){swap(arr[i],arr[largest]);
    //     heapify(arr,largest,k);
        
    // }}
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> q;
        for(int i=0;i<k;i++){
            q.push(arr[i]);
        }
        //   for(int i=0;i<k;i++){
        //  heapify(q,i,k);
        // }
        int n=arr.size();
        for(int i=k;i<n;i++){
            if(arr[i]<q.top()){
                q.pop();
                q.push(arr[i]);
        //         for(int i=0;i<k;i++){
        //  heapify(q,i,k);
      //  }
            }
        }
        return q.top();
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends