class Solution {
public:
    vector<int> current;
    vector<vector<int>> ans;
    void helper(vector<int> &nums,int i){
        if(i==nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        helper(nums,i+1);
        current.pop_back();
        helper(nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
};