class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long n=skill.size();
        long m=mana.size();
        vector<long>prefix(n+1);
        prefix[0]=0;
        for(long i=0;i<n;i++){
            prefix[i+1]=prefix[i]+skill[i];
        }
        long startime=0;
        long nextstartime=0;
        long timetaken=0;
        for(long i=0;i<m;i++){
            startime=nextstartime;
            nextstartime=0;
            for(long j=0;j<n;j++){
                timetaken=startime+mana[i]*prefix[j+1];
              if(i<m-1) { nextstartime=max(nextstartime,timetaken-prefix[j]*mana[i+1]);
              }




            }
        }
        return timetaken;

        
    }
};