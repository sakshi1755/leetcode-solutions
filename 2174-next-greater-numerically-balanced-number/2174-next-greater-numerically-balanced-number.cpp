class Solution {
public:
    bool isBalanced(int x) {
        vector<int> cnt(10, 0);
        int t = x;
        while (t > 0) {
            cnt[t % 10]++;
            t /= 10;
        }
        for (int d = 1; d <= 9; d++) {
            if (cnt[d] != 0 && cnt[d] != d)
                return false;
        }
        return cnt[0] == 0; // 0 can't appear
    }

    int nextBeautifulNumber(int n) {
        int x = n + 1;
        while (true) {
            if (isBalanced(x))
                return x;
            x++;
        }
    }
};
