class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int elem=st.top();
                elem=elem*2;
                st.push(elem);
            }
            else if(operations[i]=="+"){
                int elem1=st.top();
                st.pop();
                int elem2=st.top();
                st.push(elem1);
                elem1=elem1+elem2;
                st.push(elem1);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int sum=0;
        while(st.size()!=0){
            int elem=st.top();
            st.pop();
            sum=sum+elem;
        }
        return sum;
    }
};