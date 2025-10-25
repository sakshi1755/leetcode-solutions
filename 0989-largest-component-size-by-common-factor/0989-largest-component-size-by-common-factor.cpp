class Solution {
public:
    // class dsu{
    //     int size();
    //     vector<int>parent;
    // }
    void unite(vector<int>&parent,vector<int>&rank,int i,int num){
        int pi=findparent(parent,i);
        int ni=findparent(parent,num);
        if(pi!=ni){
            if(rank[pi]==rank[ni]){
                rank[pi]++;
                parent[ni]=pi;
            }
            else if(rank[ni]>rank[pi]){
                parent[pi]=ni;
            }
            else{
                parent[ni]=pi;
            }
        }


    }
    int findparent(vector<int>&parent,int i){
        if(parent[i]==i)return i;
        else return parent[i]=findparent(parent,parent[i]);
    }
    int largestComponentSize(vector<int>& nums) {
       int n= *max_element(nums.begin(), nums.end());
        vector<int>parent(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>rank(n+1,0);
        for(int num:nums){
            for(int i=2;i*i<=num;i++){
                if(num%i==0){
                    unite(parent,rank,i,num);
                    unite(parent,rank,num/i,num);

                }


            }
        }
        int ans=0;
        map<int,int>count;

        for(int num:nums){
            int root=findparent(parent,num);
            count[root]++;
            ans=max(ans,count[root]);
        }
        return ans;

        
    }
};