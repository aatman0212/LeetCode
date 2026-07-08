class Solution {
public:
    vector<vector<int>> answer;
    vector<int> current;
    void helper(int currentsum, int k, int n, int index) {
        if (currentsum == n && current.size() == k) {
            answer.push_back(current);
            return;
        }
        if (currentsum > n || current.size() > k) {
            return;
        }
        for(int i=index;i<=9;i++){
            current.push_back(i);
            helper(currentsum+i,k,n,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(0,k,n,1);
        return answer;
    }
};