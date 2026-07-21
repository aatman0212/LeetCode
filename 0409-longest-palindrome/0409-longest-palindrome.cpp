class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        int count = 0;
        bool firstOdd = true;

        for (char ch : s) {
            freq[ch]++;
        }

        for (int i = 0; i < 128; i++) {
            if (freq[i] % 2 == 0) {
                count += freq[i];
            } else {
                if (firstOdd) {
                    count += freq[i];
                    firstOdd = false;
                } else {
                    count += freq[i] - 1;
                }
            }
        }

        return count;
    }
};