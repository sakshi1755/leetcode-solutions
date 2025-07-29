class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            map<char,int>freq;
           // int mini=INT_MAX;
           // int maxi=INT_MIN;
            freq[s[i]]++;
            // mini=min(freq[s[i]],mini);
            // maxi=max(freq[s[i]],maxi);
            for(int j=i+1;j<n;j++){
                freq[s[j]]++;
                   int mini = INT_MAX, maxi = INT_MIN;
                for (auto &p : freq) {
                    mini = min(mini, p.second);
                    maxi = max(maxi, p.second);
                }
            ans=ans+(maxi-mini);
                // mini=min(freq[s[j]],mini);
                // maxi=max(freq[s[j]],maxi);
            }
            
            //     int mini = INT_MAX, maxi = INT_MIN;
            //     for (auto &p : freq) {
            //         mini = min(mini, p.second);
            //         maxi = max(maxi, p.second);
            //     }
            // ans=ans+(maxi-mini);
        }

        return ans;
    }
};