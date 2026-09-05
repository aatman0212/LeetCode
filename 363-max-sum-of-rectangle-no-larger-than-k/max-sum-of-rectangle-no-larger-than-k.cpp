class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        const int NEGATIVE_INF = INT_MIN;
        int maxSum = NEGATIVE_INF;
        for (int topRow = 0; topRow < rows; ++topRow) {
            vector<int> columnSums(cols, 0);
            for (int bottomRow = topRow; bottomRow < rows; ++bottomRow) {
                for (int col = 0; col < cols; ++col) {
                    columnSums[col] += matrix[bottomRow][col];
                }
                set<int> prefixSums;
                prefixSums.insert(0);
                int currentPrefixSum = 0;
                for (int colSum : columnSums) {
                    currentPrefixSum += colSum;
                    auto iterator = prefixSums.lower_bound(currentPrefixSum - k);
                  
                    if (iterator != prefixSums.end()) {
                        int subarraySum = currentPrefixSum - *iterator;
                        maxSum = max(maxSum, subarraySum);
                    }
                    prefixSums.insert(currentPrefixSum);
                }
            }
        }
      
        return maxSum;
    }
};