class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n=logs.size();
        vector<string>ll;
        vector<string>dl;
        for(int i=0;i<n;i++){
            string fs="";
            string cs=logs[i];
            int cn=cs.size();
            int j=0;
            while(cs[j]!=' '){
                fs+=cs[j];
                j++;
            }
            j++;
            string ts="";
            while(j<cn){
                ts.push_back(cs[j]);
                j++;
            }
            ts+=" ";
            ts+=fs;
            if(ts[0]>='a' && ts[0]<='z'){
                ll.push_back(ts);
            }
            else{
                dl.push_back(cs);
            }


        }
        vector<string>ans;
        sort(ll.begin(),ll.end());
       // sort(dl.begin(),dl.end());
        for(int i=0;i<ll.size();i++){
            string cs=ll[i];
            string fs="";
            int cn=cs.size();
            int j=cn-1;
            while(cs[j]!=' '){
                fs+=cs[j];
                cs.pop_back();
                j--;
            }
            reverse(fs.begin(),fs.end());
            j--;
            cs.pop_back();
            cs=fs+" "+cs;
            ans.push_back(cs);

        }
        for(int i=0;i<dl.size();i++){
            string cs=dl[i];
            // string fs="";
            // int cn=cs.size();
            // int j=cn-1;
            // while(cs[j]!=' '){
            //     fs+=cs[j];
            //     cs.pop_back();
            //     j--;
            // }
            // j--;
            // cs.pop_back();
            // cs=fs+" "+cs;
            ans.push_back(cs);

        }
        return ans;
        
    }
};