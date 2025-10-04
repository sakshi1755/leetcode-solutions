class Solution {
public:
    int maxArea(vector<int>& height) {
        long long n=height.size();
        long long  l=0;
        long long r=n-1;
        long long ans=0;
        while(l<r){
            ans=max(ans,((min(height[l],height[r]))*(r-l)));
            if(height[l]<height[r])l++;
            else r--;


            
        }
        return ans;





        
        
    }
};