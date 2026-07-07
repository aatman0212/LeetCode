class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void helper(int nums,int index,int k){
        if(current.size()==k){
            ans.push_back(current);
            return;
        }
        for(int i=index;i<=nums;i++)
        {
            current.push_back(i);
            helper(nums,i+1,k);
            current.pop_back();
        }        
    }
    vector<vector<int>> combine(int n, int k) {
        helper(n,1,k);
        return ans;
    }
};