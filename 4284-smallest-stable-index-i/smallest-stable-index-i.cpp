class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> arr(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            int maximum = nums[0];
            int minimum = nums[i];

            for(int j = 0; j <= i; j++) {
                maximum = max(nums[j], maximum);
            }

            for(int j = i; j < nums.size(); j++) {
                minimum = min(nums[j], minimum);
            }

            arr[i] = maximum - minimum;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(arr[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};