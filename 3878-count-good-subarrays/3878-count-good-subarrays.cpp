class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>r(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                int t=st.top();
                if((nums[i]|nums[t])==nums[i] && nums[i]!=nums[t]){
                    st.pop();

                }
                else break;
            }

            if(!st.empty()){
                r[i]=st.top();
            }
            else r[i]=n;
            st.push(i);
        }


        stack<int>rst;
        vector<int>l(n);
        for(int i=0;i<n;i++){
            while(!rst.empty() && (nums[i]|nums[rst.top()])==nums[i]){
                rst.pop();
            }

            if(!rst.empty()){
                l[i]=rst.top();
            }
            else l[i]=-1;
            rst.push(i);


        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=i-l[i];
            long long right=r[i]-i;
            ans+=(right*left);

        }
        return ans;

        

        
        
    }
};