class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long a = dividend;
        long long b = divisor;
        bool negative = (a < 0) ^ (b < 0);
        a = abs(a);
        b = abs(b);
        long long q = 0;
        while (a >= b) {
            long long c = b;
            long long count = 1;
            while (c + c <= a) {
                c += c;
                count += count;
            }
            a -= c;
            q += count;
        }
        if (negative)
            q = -q;
        return q;
    }
};