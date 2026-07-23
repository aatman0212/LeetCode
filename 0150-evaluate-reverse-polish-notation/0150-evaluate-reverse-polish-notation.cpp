class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int elem1=st.top();
                st.pop();
                int elem2=st.top();
                st.pop();
                elem1=elem1+elem2;
                st.push(elem1);
            }
            else if(tokens[i]=="-"){
                int elem1=st.top();
                st.pop();
                int elem2=st.top();
                st.pop();
                elem1=elem2-elem1;
                st.push(elem1);
            }
            else if( tokens[i]=="*"){
                int elem1=st.top();
                st.pop();
                int elem2=st.top();
                st.pop();
                elem1=elem2*elem1;
                st.push(elem1);
            }
            else if(tokens[i]=="/"){
                int elem1=st.top();
                st.pop();
                int elem2=st.top();
                st.pop();
                elem1=elem2/elem1;
                st.push(elem1);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        int ans=st.top();
        return ans;
    }
};