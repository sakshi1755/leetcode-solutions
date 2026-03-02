class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)arr[i]++;
                else break;
            }


        }
        vector<int>temp=arr;
        sort(temp.begin(),temp.end(),greater<int>());
        bool isa=true;
        for(int i=0;i<n;i++){
            if(temp[i]<n-i-1){
                isa=false;

            }
            

        }
        if(!isa)return -1;
        int ans=0;
        for(int i=n-1;i>=1;i--){
            int si=n-1-i;
            int f=-1;
            for(int j=si;j<n;j++ ){
                if(arr[j]>=i){f=j;
                break;
                }

                
            }
            int c=f;
            while(c!=si){
                swap(arr[c],arr[c-1]);
                c--;
                ans++;
            }

        }
        return ans;
        
    }
};