class Solution {
public:
    bool rotateString(string s, string goal) {

        vector<int>ind;
        char t=s[0];
        int n=s.size();
        int n2=goal.size();
        if(n!=n2)return false;
        bool ans=false;
        for(int i=0;i<n;i++){
            if(s[i]==t)ind.push_back(i);
        }
        for(int i=0;i<ind.size();i++){
            if(goal.find(t) ==string::npos)return false;
            int r=goal.find(t)+1;
            int l=ind[i]+1;
            if(r>=n)r=0;
            if(l>=n)l=0;
            
            while(l!=i){
               if(s[l]!=goal[r])break;
               l++;
               r++;
               if(r>=n)r=0;
               if(l>=n)l=0;
            
               if(l==i)return true;
            }
        }
    return false;     
    }
};