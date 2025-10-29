class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans=0;
        int m=flowerbed.size();
        if(m==1){
             if(flowerbed[0]==0 ){
            ans++;
            if(ans<n)return false;
        else return true;

        }
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            ans++;
            flowerbed[0]=1;
        }
        for(int i=1;i<m-1;i++){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    ans++;
                    flowerbed[i]=1;
                }
            }
        }
        if(flowerbed[m-1]==0 && flowerbed[m-2]==0){
            ans++;
            flowerbed[m-1]=1;
        }
        if(ans<n)return false;
        else return true;
    }
};