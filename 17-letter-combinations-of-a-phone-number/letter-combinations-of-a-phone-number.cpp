class Solution {
public:
    string current;
    vector<string> answer;
    vector<string> keypad = {
    "",     
    "",     
    "abc",  
    "def",  
    "ghi",  
    "jkl",  
    "mno",  
    "pqrs", 
    "tuv",  
    "wxyz"
    };
    void helper(string digits , int index){
        if(digits.size()==current.size()){
            answer.push_back(current);
            return;
        }
        for (char ch : keypad[digits[index] - '0'])
        {
            current.push_back(ch);
            helper(digits,index+1);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }
        helper(digits,0);
        return answer;
    }
};