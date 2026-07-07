class Solution {
public:
    vector<vector<int>> answer;
    vector<int> current;
    vector<bool> used;

    void helper(vector<int>& nums)
    {
        if(nums.size()==current.size()){
            answer.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(used[i]){
                continue;
            }
            current.push_back(nums[i]);
            used[i] = true;
            helper(nums);
            used[i] = false;
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        helper(nums);
        return answer;
    }
};