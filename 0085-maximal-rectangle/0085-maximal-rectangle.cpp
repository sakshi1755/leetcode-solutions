class Solution {
public:
    int solve(vector<int>&h){
        int n= h.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
           
                while(!s.empty() && s.top().second >=h[i]) s.pop();

                if(!s.empty())left[i]=s.top().first;
                else left[i]=0;
                s.push({i+1,h[i]});
            





        }
        
        stack<pair<int,int>>s2;
        for(int i=n-1;i>=0;i--){
             while(!s2.empty() && s2.top().second >= h[i]) s2.pop();

                if(!s2.empty())right[i]=s2.top().first;
                else right[i]=n+1;
                s2.push({i+1,h[i]});
            

        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(right[i]-left[i]-1)*h[i]);
        }
        return maxi;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>h(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(matrix[i][j]=='1') h[j]++;
               else h[j]=0; 
            }
            maxi=max(maxi,solve(h));

        }
        return maxi;




        
    }
};