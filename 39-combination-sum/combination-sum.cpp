class Solution {
public:
    vector<vector<int>> answer;
    vector<int> current;

    void helper(vector<int>& candidates,int remaining,int index)
    {
    if (remaining==0)
    {
        answer.push_back(current);
        return;
        
    }
    if (remaining<0)
    {
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        current.push_back(candidates[i]);
        helper(candidates,remaining-candidates[i],i);
        current.pop_back();
    }
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0);
        return answer;
    }
};