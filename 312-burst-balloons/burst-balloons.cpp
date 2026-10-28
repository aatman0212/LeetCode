class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            balloons[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    int coins = dp[i][k] + dp[k][j] + 
                               balloons[i] * balloons[k] * balloons[j];
                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }
        return dp[0][n + 1];
    }
};