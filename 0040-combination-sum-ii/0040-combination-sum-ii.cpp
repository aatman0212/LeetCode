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
        if (i > index && candidates[i] == candidates[i - 1]){
            continue;
        }
        current.push_back(candidates[i]);
        helper(candidates,remaining-candidates[i],i+1);
        current.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return answer;
    
    }
};