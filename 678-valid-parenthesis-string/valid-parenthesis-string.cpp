class Solution {
public:
    bool checkValidString(string s) {
        int n=0;
        int low=0,high=0;
        while(s.length()!=n){
            if(s[n]=='('){
                low++;
                high++;
            }
            else if(s[n]==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }
            low=max(0,low);
            if(high<0){
                return false;
            }
            n++;
        }
        return low==0;
    }
};