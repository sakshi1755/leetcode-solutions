class Solution {
public:
    vector<int> todate(string s){
        vector<int>ans;
        string curr="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                ans.push_back(stoi(curr));
                curr="";
            }
            else{
                curr+=s[i];
            }
        }
        ans.push_back(stoi(curr));
        return ans;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string sd=max(arriveAlice, arriveBob);
        string ed=min(leaveAlice, leaveBob);
        if(ed<sd)return 0;
        vector<int>m={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>startdate=todate(sd);
        vector<int>enddate=todate(ed);
        int sm=startdate[0];
        int sdt=startdate[1];
        int em=enddate[0];
        int edt=enddate[1];
        if(sm==em){
            return edt-sdt+1;
        }
        else{
            long long ans=0;
            ans+=(m[sm-1]-sdt+1);
            ans+=edt;
            for(int i=sm+1;i<em;i++){
                ans+=m[i-1];
            }
            return ans;

        }






        
    }
};