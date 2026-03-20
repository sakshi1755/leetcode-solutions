class Solution {
public:
    int findparent(int i,vector<int>&parent){
        if(parent[i]==i)return parent[i];
        else{
            return parent[i]=findparent(parent[i],parent);
        }
    }
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<pair<int,int>>num;
        for(int i=0;i<n;i++){
            num.push_back({nums[i],i});
        }
        vector<int>parent(maxi+1);
        vector<int>primenumbers;
        map<int,bool>isnprime;
        for(int i=2;i<=maxi;i++){
            for(int j=2;j*i<=maxi;j++){
                isnprime[i*j]=true;


            }
        }
        for(int i=2;i<=maxi;i++){
            if(!isnprime[i])primenumbers.push_back(i);
        }
        vector<int>rank(maxi+1,0);
        for(int i=0;i<maxi+1;i++){
            parent[i]=i;
        }
        // vector<pair<int,int>>sortnum=num;
        // sort(sortnum.begin(),sortnum.end());
        // map<int,int>sortp;
        // for(int i=0;i<n;i++){
        //     sortp[sortnum[i].second]=i;
        // }
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=0;j<primenumbers.size() &&primenumbers[j]<=num;j++){
                if(num%primenumbers[j]==0){
                  int  pn=findparent(nums[i],parent);
                  int  pp=findparent(primenumbers[j],parent);
                    if(pn!=pp){
                        if(rank[pp]>=rank[pn]){
                            parent[pn]=pp;
                        }
                        else{
                            parent[pp]=pn;
                        }
                    }
                 while(num%primenumbers[j]==0){
                    num/=primenumbers[j];
                 }
                }
            }
        }
        vector<int>sortedarray=nums;
        sort(sortedarray.begin(),sortedarray.end());
        for(int i=0;i<n;i++){
            if(findparent(nums[i],parent)!=findparent(sortedarray[i],parent))return false;

        }
        return true;



        
        
    }
};