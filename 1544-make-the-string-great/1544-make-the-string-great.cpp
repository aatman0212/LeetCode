class Solution {
public:
    string makeGood(string s) {
        string stack;
        for (char currentChar : s) {
            if (stack.empty() || abs(stack.back() - currentChar) != 32) {
                stack += currentChar;
            } else {
                stack.pop_back();
            }
        }
        return stack;
    }
};