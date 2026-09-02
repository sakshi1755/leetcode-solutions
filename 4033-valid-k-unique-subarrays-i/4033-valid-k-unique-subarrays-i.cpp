// 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void add(int index, vector<int>& nums, vector<int>& freq, int& distinct, int& odd) {
        int num = nums[index];
        freq[num]++;
        if (freq[num] == 1) {
            distinct++;
        }
        if (freq[num] % 2 == 1) {
            odd++;
        } else {
            odd--;
        }
    }
    void remove(int index, vector<int>& nums, vector<int>& freq, int& distinct, int& odd) {
        int num = nums[index];
        freq[num]--;
        if (freq[num] == 0) {
            distinct--;
        }
        if (freq[num] % 2 == 1) {
            odd++;
        } else {
            odd--;
        }
    }
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        vector<vector<int>>qs;
        for(int i=0;i<q;i++){
            qs.push_back({queries[i][0],queries[i][1],i});
        }
        int bs=sqrt(n);
        sort(qs.begin(),qs.end(),[&](auto &a, auto &b){
            int ba=a[0]/bs;
            int bb=b[0]/bs;
            if(ba!=bb){
                return ba<bb;
            }
            return a[1]<b[1];
        });
        int maxi=*max_element(nums.begin(),nums.end());
        int     L=0;
        int R=-1;
        int distinct=0;
        int odd=0;
        vector<int>freq(maxi+1,0);
        vector<bool>ans(q,false);
        for(int i=0;i<q;i++){
            int l=qs[i][0];
            int r=qs[i][1];
            int ind=qs[i][2];
            while(L>l){
                L--;
                add(L,nums,freq,distinct,odd);


            }
            while(R<r){
                R++;
                add(R,nums,freq,distinct,odd);
            }
            while(L<l){
                remove(L,nums,freq,distinct,odd);
                L++;
            }
            while(R>r){
                remove(R,nums,freq,distinct,odd);
                R--;
            }
            if(distinct==k && odd==0){
                ans[ind]=true;
            }
        }
        return ans;
        
    }
};
