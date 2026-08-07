class Solution {
public:
    bool isValid(string s) {
        if(s.size()%3!=0){
            return false;
        }
        string st;
        for(char c:s){
            st.push_back(c);
            if(st.size()>=3 && st.substr(st.size()-3,3)=="abc"){
                st.erase(st.end()-3,st.end());
            }
        }
        return st.empty();
    }
};