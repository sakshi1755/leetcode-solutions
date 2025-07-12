class Solution {
public:
    int divide(int dividend, int divisor) {
        // The only overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Work with long long to avoid overflow during abs()
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        result = negative ? -result : result;

        return (int)result;  // Will always be in bounds (except the one case above)
    }
};
