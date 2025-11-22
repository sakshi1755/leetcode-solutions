class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        // A is smaller than a by 32
        string sf;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-')
                continue;
            else {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    sf.push_back(s[i] - 32);
                } else {
                    sf.push_back(s[i]);
                }
            }
        }
        cout << sf << " ";
        string ans;
        int z = sf.size();
        if(z==0 || z<=k)return sf;
        int f = z % k;
        if (f == 0)
            f = k;
        cout << f << " ";
        for (int i = 0; i < f; i++) {
            ans.push_back(sf[i]);
        }

        cout << ans << " ";
        ans.push_back('-');
        while (f < z) {
            for (int i = f; i <f+ k; i++) {
                ans.push_back(sf[i]);
            }
            ans.push_back('-');
            f = f + k;
        }
        if(ans.back()=='-')ans.pop_back();
        return ans;
    }
};