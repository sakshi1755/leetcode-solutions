class Solution {
public:
    bool canAliceWin(int n) {
        int removed=10;
        int turn=0;
        while(n-removed >= 0){
            n=n-removed;
            removed--;
            turn=(turn+1)%2;
        }
        if(turn==0) return false;
        else return true;
        
    }
};