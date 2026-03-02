class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        map<pair<int,int>,bool>isnotallowed;
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=18;i>=0;i--){
            int num=1<<i;
            int tne=false;
            for(int j=0;j<m;j++){
                int tras=true;
                int andi=(1<<21)-1;
                for(int k=0;k<n;k++){
                    //isallowed numbers ka and
                    if(!isnotallowed[{j,k}]) andi=andi & grid[j][k];


                }
                //allowed nums ka and has the num then the num exits tne adnd tras the row allows skipping is false;
                if((andi & num)==num){
                    tras=false;
                }
                if(!tras){
                    tne=true;
                    break;
                }
            }
            if(tne){
                ans=ans|num;
            }
            else{
                //remove elements that have it 
                for(int j=0;j<m;j++){
                    for(int k=0;k<n;k++){
                        if((grid[j][k] & num)==num){
                            isnotallowed[{j,k}]=true;
                        }
                    }
                }

            }
            


        }
        return ans;
        
    }
};
