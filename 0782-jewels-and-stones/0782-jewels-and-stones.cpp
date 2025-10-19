class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,bool>j;
        for(int i=0;i<jewels.size();i++){
            j[jewels[i]]=true;
        }
        long long ans=0;
        for(int i=0;i<stones.size();i++){
               if(j[stones[i]])ans++;
        }
        return ans;
        
    }
};