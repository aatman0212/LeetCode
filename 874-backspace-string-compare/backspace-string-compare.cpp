class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> ts;
        int i=0;
        while(i<s.length()){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        i=0;
        while(i<t.length()){
            if(t[i] == '#'){
                if(!ts.empty()){
                    ts.pop();
                }
            }           
            else{
                ts.push(t[i]);
            }
            i++;
        }
        i=0;
        if(st.size()!=ts.size()){
            return false;
        }
        while(st.size()!=0){
            char elem=st.top();
            char elem2=ts.top();
            if(elem==elem2){
                st.pop();
                ts.pop();
            }
            else{
                return false;
            }
            i++;
        }
        return true;
    }
};