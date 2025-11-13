class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();

            }
            if(!st.empty())left[i]=st.top().second;
            st.push({heights[i],i});
        }
           stack<pair<int,int>>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && st2.top().first>=heights[i]){
                st2.pop();

            }
            if(!st2.empty())right[i]=st2.top().second;
            st2.push({heights[i],i});
        }
        int maxiarea=0;
        for(int i=0;i<n;i++){
            int temparea=(right[i]-left[i]-1)*heights[i];
            maxiarea=max(temparea,maxiarea);

        }
        return maxiarea;
        

        
    }
};