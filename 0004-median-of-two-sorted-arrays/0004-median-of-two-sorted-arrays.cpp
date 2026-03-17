class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        for (int i=0; i<n;i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        float ans;
        int a1=(m+n)/2-1;
        int a2=(m+n)/2;
        //cout<<nums1[a2];
        //cout<<nums1[a1];
        if((m+n)%2==0){
            float ans1=(nums1[a1]+ nums1[a2]);
            //cout<<ans1;
            ans=ans1/2.0;
        }
        else{
            ans=nums1[a2];
        }
        return ans;
    }
};