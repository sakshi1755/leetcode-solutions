class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<long long>odd(n); //leaving that number
        odd[n-1]=0;
        vector<long long>even(n);
        even[n-1]=0;
        for(int i=n-2; i>=0;i--){
            if((i+1)%2==0){
                even[i]=even[i+1]+nums[i+1];
                odd[i]=odd[i+1];
            }
            else{
                odd[i]=odd[i+1]+nums[i+1];
                even[i]=even[i+1];
            }

        }
        long long alleven=even[0]+nums[0];
        long long allodd=odd[0];
        long long ans=0;
        for(int i=0;i<n;i++){
            long long tempeven, tempodd;
            if(i%2==0){ tempeven=alleven-nums[i]-even[i]+odd[i];
            tempodd=allodd-odd[i]+even[i];
            }
            else { tempeven=alleven-even[i]+odd[i];
                 tempodd=allodd-nums[i]+even[i]-odd[i];
            }            

            if(tempeven==tempodd)ans++;
        }
        return ans;

        
    }
};