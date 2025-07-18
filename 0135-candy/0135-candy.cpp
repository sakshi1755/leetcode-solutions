class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>right(n,1);
        vector<int>left(n,1);
         vector<int>candies(n,1);

    
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                left[i]=left[i+1]+1;
            }
        } 
        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                right[i]=right[i-1]+1;
            }
        }
        for(int i=0;i<n;i++){
            candies[i]=max(left[i],right[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=candies[i];

        }
        return ans;
        
    }
};