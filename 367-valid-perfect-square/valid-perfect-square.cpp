class Solution {
public:
    bool isPerfectSquare(int num) {
        double ans=num;
        for (int i = 0; i < 50; i++) {
            ans = (ans + num / ans) / 2;
        }
        return ans==(int)ans;
    }
};