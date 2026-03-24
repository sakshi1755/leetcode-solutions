class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        map<int,int>f;
        map<int,int>f1;
        for(int i=0;i<n;i++){
            f[nums1[i]]++;
            f1[nums1[i]]++;
            f[nums2[i]]++;
        }
        for(auto t: f){
            if(t.second%2!=0)return -1;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(f1[nums1[i]]>(f[nums1[i]]/2)){
                ans+=(f1[nums1[i]]-f[nums1[i]]/2);
                f1[nums1[i]]=0;

            }
            

        }
        return ans;
        
    }
};