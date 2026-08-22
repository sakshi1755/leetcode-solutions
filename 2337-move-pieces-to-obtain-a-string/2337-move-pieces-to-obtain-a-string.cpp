class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int startkel=0;
        int startker=0;
        int targetkel=0;
        int targetker=0;
        for(int i=0;i<n;i++){
            if(start[i]=='L'){
                startkel++;
            }
            if(start[i]=='R'){
                startker++;
            }
            if(target[i]=='L'){
                targetkel++;
            }
            if(target[i]=='R'){
                targetker++;
            }



            
            if(startkel>0 && startker>0){
                return false;
            }
            if(startker>0 && targetkel>0){
                return false;
            }
            if(startkel>0 && targetker>0){
                return false;
            }
            if(startkel<=targetkel){
                targetkel-=startkel;
                startkel=0;
            }
            if(startkel>targetkel){
                return false;
            }
            if(targetker<=startker){
                startker-=targetker;
                targetker=0;
            }
            if(targetker>startker){
                return false;
            }

                        
        }
        
        if(startkel==0 && startker==0 && targetkel==0 && targetker==0)return true;
        else return false;
        
    }
};