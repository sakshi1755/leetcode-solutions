class Solution {
public:
double myPow(double x, int n) {
    if(n == 0) return 1;
    long long N = n;   // To avoid overflow when n == INT_MIN
    if(N < 0) {
        x = 1 / x;
        N = -N;
    }
    double half = myPow(x, N / 2);
    if(N % 2 == 0) return half * half;
    else return half * half * x;
}

};