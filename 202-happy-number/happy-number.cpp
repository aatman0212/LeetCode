class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visitedNumbers;
        while (n != 1 && !visitedNumbers.count(n)) {
            visitedNumbers.insert(n);
            int sumOfSquares = 0;
            while (n > 0) {
                int digit = n % 10;
                sumOfSquares += digit * digit;
                n /= 10;
            }
            n = sumOfSquares;
        }
        return n == 1;
    }
};