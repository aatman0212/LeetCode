class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivotIndex = n - 2;
        while (pivotIndex >= 0) {
            if (nums[pivotIndex] < nums[pivotIndex + 1]) {
                break;
            }
            pivotIndex--;
        }
        if (pivotIndex >= 0) {
            for (int swapIndex = n - 1; swapIndex > pivotIndex; swapIndex--) {
                if (nums[swapIndex] > nums[pivotIndex]) {
                    swap(nums[pivotIndex], nums[swapIndex]);
                    break;
                }
            }
        }
        int left = pivotIndex + 1;
        int right = n - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};