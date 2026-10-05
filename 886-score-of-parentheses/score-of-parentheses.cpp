class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                if (st.top() == 0) {
                    st.pop();
                    st.push(1);
                } else {
                    int score = 0;
                    while (st.top() != 0) {
                        score += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2 * score);
                }
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};