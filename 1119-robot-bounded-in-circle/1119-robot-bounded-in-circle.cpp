class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n=instructions.size();
        int x=0;
        int y=0;
        int d=0;
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<n;i++){
            if(instructions[i]=='G'){
                x+=dir[d].first;
                y+=dir[d].second;
            }
            else if(instructions[i]=='L'){
                d=(d+3)%4;
            }
            else {
                d=(d+1)%4;
            }
        }
        if((x==0 && y==0))return true;
        if(d!=0)return true;
        return false;


        
    }
};