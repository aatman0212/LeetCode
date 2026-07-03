class Solution {
public:
    int maxlen =0;
    int bestleft=0;
    void expand(const string& s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            int currlength=right-left+1;
            if(currlength>maxlen){
                maxlen=currlength;
                bestleft=left;
            }
            left--;
            right++;
        }
        
    }
    string longestPalindrome(string s) {
        if (s.empty()){
            return "";
        }
        maxlen = 0;
        bestleft = 0;
        for (int i =0;i<s.length();i++){
            expand(s,i, i);
            expand(s,i, i + 1);
        }
        return s.substr(bestleft,maxlen);
    }
};