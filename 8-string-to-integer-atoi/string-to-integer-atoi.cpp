class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int length = s.size();
        while (index < length && s[index] == ' ') {
            ++index;
        }
        if (index == length) return 0;
        int sign = 1;
        if (s[index] == '-') {
            sign = -1;
        }
        if (s[index] == '-' || s[index] == '+') {
            ++index;
        }
        int result = 0;
        int overflowThreshold = INT_MAX / 10;
        while (index < length) {
            if (!isdigit(s[index])) {
                break;
            }
            int digit = s[index] - '0';
            if (result > overflowThreshold || 
                (result == overflowThreshold && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            ++index;
        }
        return result * sign;
    }
};
