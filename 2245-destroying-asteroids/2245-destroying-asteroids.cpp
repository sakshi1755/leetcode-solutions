class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int m = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] <= m) {
                if (m > INT_MAX - asteroids[i]) return true; // would overflow int
                m += asteroids[i];
            } else {
                return false;
            }
        }
        return true;
    }
};
