class Solution {
public:
    bool isemail(string& s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char s1 = s[i];
            if (s1 >= 'A' && s1 <= 'Z') {
                return true;
            }
            if (s1 >= 'a' && s1 <= 'z') {
                return true;
            }
        }
        return false;
    }
    string maskPII(string s) {
        int n = s.size();
        string ans;
        if (!isemail(s)) {
            string sf;
            for (int i = 0; i < n; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    sf.push_back(s[i]);
                }
            }

            int z = sf.size();
            if (z > 10)
                ans.push_back('+');
            for (int i = 10; i < (z); i++) {
                ans.push_back('*');
            }
            if (z > 10)
                ans.push_back('-');
            ans += "***-***-";
            for(int i=z-4;i<z;i++){
                ans.push_back(sf[i]);
            }

        } else {
            char s1 = s[0];

            // A is smaller than a
            if (s1 >= 'A' && s1 <= 'Z') {
                s1 = s1 + 32;
            }
            int ar = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == '@') {
                    ar = i;
                    break;
                }
            }
            ans.push_back(s1);
            ans += "*****";
            char s2 = s[ar - 1];
            if (s2 >= 'A' && s2 <= 'Z') {
                s2 = s2 + 32;
            }
            ans.push_back(s2);

            for (int i = ar; i < n; i++) {
                char s3 = s[i];
                if (s3 >= 'A' && s3 <= 'Z') {
                    s3 = s3 + 32;
                }
                ans.push_back(s3);
            }
        }
        return ans;
    }
};