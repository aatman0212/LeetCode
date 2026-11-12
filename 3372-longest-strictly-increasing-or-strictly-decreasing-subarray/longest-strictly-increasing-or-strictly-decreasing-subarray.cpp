class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 1;
        for (int i = 1, currentLength = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 1;
            }
        }      
        for (int i = 1, currentLength = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 1;
            }
        }
      
        return maxLength; 
    }
};
