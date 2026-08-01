class Solution {
public:
    int maxDepth(string s) {
        int ans=0,d=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                d++;
                ans=max(d,ans);
            }
            else  if(s[i]==')'){
                d--;
            }
        }
        return ans;
    }
};