
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
              int n = arr.size();
              int start=0;
              int end=n-1;
              int startlen=1;
              int endlength=1;
              for(int i=1;i<n;i++){
                  startlen++;
                  if(arr[i]<arr[i-1])
                  {
                    start=i;
                    startlen--;
                    break;
                  }
              }  
               if(start==0)return 0;    
              for(int i=n-2;i>=0;i--){
                  endlength++;
                  if(arr[i]>arr[i+1])
                  {
                    end=i;
                    endlength--;
                    break;
                  }
                }
        if(arr[end+1]>=arr[start-1])return end-start+1;
        int ans=min(n-start,end+1);
        if(startlen==1 || endlength==1) return ans;
        int i=0;
        int j=end+1;
        while(i<start && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }
            else j++;   


        }
        return ans;
        
    }
};
// @lc code=end

