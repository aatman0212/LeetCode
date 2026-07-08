class Solution {
public:
    vector<vector<string>> answer;
    vector<string> current;

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void helper(string &s, int index) {
        if (index == s.size()) {
            answer.push_back(current);
            return;
        }

        for (int end = index; end < s.size(); end++) {
            if (isPalindrome(s, index, end)) {
                current.push_back(s.substr(index, end - index + 1));
                helper(s, end + 1);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        helper(s, 0);
        return answer;
    }
};