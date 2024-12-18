//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
         
          int count=0;
        int n=arr.size();
         vector<int>ans ;
        if(n<k) return vector<int>();;
        queue<int> q;
        for(int i=0; i<k; i++){
            q.push(arr[i]);
            
            
        }
        int i=0;
        while(i<n){
            if(i>=count+k-1 && arr[i]>0){
               ans.push_back(0);
              if(count+k<n) q.push(arr[count+k]);
                count++;
                
            }
         else   {if(q.front()<0){
                ans.push_back(q.front());

                 if(i<=count) q.pop();
                
              
               if(count+k<n) q.push(arr[count+k]);
               else break;
                 if(i<=count)  i++;
                 count++;
                //continue;
            }
            else{
                q.pop();
                i++;
            }
         }
        }
    return ans;
        // write code here
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
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends